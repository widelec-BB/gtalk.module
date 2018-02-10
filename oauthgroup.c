/*
 * Copyright (c) 2015 - 2018 Filip "widelec" Maryjanski, BlaBla group.
 * All rights reserved.
 * Distributed under the terms of the GNU Lesser General Public License v2.1.
 */

#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/locale.h>
#include <proto/openurl.h>
#include <mui/Hyperlink_mcc.h>
#include <libvstring.h>
#include "globaldefines.h"
#include "locale.h"
#include "class.h"
#include "oauthgroup.h"

extern struct Library *SysBase, *MUIMasterBase, *UtilityBase, *LocaleBase, *OpenURLBase;

struct MUI_CustomClass *OAuthGroupClass;

struct OAuthGroupData
{
	struct ObjData *oagd_ModuleData;
	STRPTR oagd_AuthToken, oagd_RefreshToken;
	Object *oagd_AuthorizedText;
	Object *oagd_ManualGroup;
	Object *oagd_AuthButtonsGroup;
	Object *oagd_RemAuthGroup;
};

static IPTR OAuthGroupDispatcher(VOID);
const struct EmulLibEntry OAuthGroupGate = {TRAP_LIB, 0, (VOID(*)(VOID))OAuthGroupDispatcher};

struct MUI_CustomClass *CreateOAuthGroupClass(VOID)
{
	struct MUI_CustomClass *cl;

	cl = MUI_CreateCustomClass(NULL, MUIC_Group, NULL, sizeof(struct OAuthGroupData), (APTR)&OAuthGroupGate);
	OAuthGroupClass = cl;
	return cl;
}

VOID DeleteOAuthGroupClass(VOID)
{
	if (OAuthGroupClass) MUI_DeleteCustomClass(OAuthGroupClass);
}

static IPTR OAuthGroupNew(Class *cl, Object *obj, struct opSet *msg)
{
	Object *key_button = NormalButton(GetString(MSG_PREFS_OAUTH_KEY_BUTTON), *GetString(MSG_PREFS_OAUTH_KEY_BUTTON_HOTKEY), USD_PREFS_OAUTH_KEY_BUTTON, 1, GetString(MSG_PREFS_OAUTH_KEY_BUTTON_HELP));
	Object *manual_button = NormalButton(GetString(MSG_PREFS_OAUTH_KEY_MANUAL_BUTTON), *GetString(MSG_PREFS_OAUTH_KEY_MANUAL_HOTKEY), USD_PREFS_OAUTH_KEY_MANUAL_BUTTON, 1, GetString(MSG_PREFS_OAUTH_KEY_MANUAL_BUTTON_HELP));
	struct ObjData *mod_data = (struct ObjData*)GetTagData(OAGA_ModuleObjectData, (IPTR)NULL, (struct TagItem*)msg->ops_AttrList);
	Object *atext, *manual_group, *auth_buttons_group, *manual_done_button, *manual_code_string, *rem_authorization_group;
	Object *rem_authorization_button = NormalButton(GetString(MSG_PREFS_OAUTH_REMOVE_BUTTON), *GetString(MSG_PREFS_OAUTH_REMOVE_BUTTON_HOTKEY), USD_PREFS_OAUTH_REMOVE_BUTTON, 1, GetString(MSG_PREFS_OAUTH_REMOVE_BUTTON_HELP));

	obj = (Object*)DoSuperNew((IPTR)cl, (IPTR)obj,
		MUIA_Frame, MUIV_Frame_Group,
		MUIA_FrameTitle, (IPTR)GetString(MSG_PREFS_OAUTH),
		MUIA_Background, MUII_GroupBack,
		MUIA_Group_Child, (IPTR)MUI_NewObjectM(MUIC_Floattext,
			MUIA_Background, "",
			MUIA_Floattext_Text, (IPTR)GetString(MSG_PREFS_OAUTH_EXPLANATION),
		TAG_END),
		MUIA_Group_Child, (IPTR)(auth_buttons_group = MUI_NewObjectM(MUIC_Group,
			MUIA_Group_Horiz, TRUE,
			MUIA_Group_Child, (IPTR)EmptyRectangle(100),
			MUIA_Group_Child, (IPTR)key_button,
			MUIA_Group_Child, (IPTR)manual_button,
			MUIA_Group_Child, (IPTR)EmptyRectangle(100),
		TAG_END)),
		MUIA_Group_Child, (IPTR)(atext = MUI_NewObjectM(MUIC_Group,
			MUIA_ShowMe, FALSE,
			MUIA_Group_Horiz, TRUE,
			MUIA_Group_Child, (IPTR)EmptyRectangle(100),
			MUIA_Group_Child, (IPTR)MUI_NewObjectM(MUIC_Text,
				MUIA_Text_Contents, GetString(MSG_PREFS_OAUTH_AUTHORIZED),
			TAG_END),
			MUIA_Group_Child, (IPTR)EmptyRectangle(100),
		TAG_END)),
		MUIA_Group_Child, (IPTR)(rem_authorization_group = MUI_NewObjectM(MUIC_Group,
			MUIA_ShowMe, FALSE,
			MUIA_Group_Horiz, TRUE,
			MUIA_Group_Child, (IPTR)EmptyRectangle(100),
			MUIA_Group_Child, (IPTR)rem_authorization_button,
			MUIA_Group_Child, (IPTR)EmptyRectangle(100),
		TAG_END)),
		MUIA_Group_Child, (IPTR)(manual_group = MUI_NewObjectM(MUIC_Group,
			MUIA_ShowMe, FALSE,
			MUIA_Group_Child, (IPTR)MUI_NewObjectM(MUIC_Group,
				MUIA_Group_Columns, 2,
				MUIA_Group_Child, (IPTR)StringLabel(GetString(MSG_PREFS_OAUTH_MANUAL_URL_TITLE), "\33r"),
				MUIA_Group_Child, (IPTR)MUI_NewObjectM(MUIC_Group,
					MUIA_Group_Horiz, TRUE,
					MUIA_Group_Child, (IPTR)EmptyRectangle(100),
					MUIA_Group_Child, (IPTR)MUI_NewObjectM(MUIC_Hyperlink,
						MUIA_Hyperlink_URI, GOOGLE_AUTH_URL,
						MUIA_Hyperlink_Text, (IPTR)GetString(MSG_PREFS_OAUTH_MANUAL_URL_HELP),
					TAG_END),
					MUIA_Group_Child, (IPTR)EmptyRectangle(100),
				TAG_END),
				MUIA_Group_Child, (IPTR)StringLabel(GetString(MSG_PREFS_OAUTH_MANUAL_TOKEN_TITLE), "\33r"),
				MUIA_Group_Child, (IPTR)(manual_code_string = MUI_NewObjectM(MUIC_String,
					MUIA_Frame, MUIV_Frame_String,
					MUIA_Background, MUII_StringBack,
					MUIA_CycleChain, TRUE,
					MUIA_String_AdvanceOnCR, TRUE,
					MUIA_ShortHelp, (IPTR)GetString(MSG_PREFS_OAUTH_MANUAL_TOKEN_HELP),
				TAG_END)),
			TAG_END),
			MUIA_Group_Child, (IPTR)MUI_NewObjectM(MUIC_Group,
				MUIA_Group_Horiz, TRUE,
				MUIA_Group_Child, (IPTR)EmptyRectangle(100),
				MUIA_Group_Child, (IPTR)(manual_done_button = NormalButton(GetString(MSG_PREFS_OAUTH_MANUAL_DONE_BUTTON), *GetString(MSG_PREFS_OAUTH_KEY_MANUAL_HOTKEY), USD_PREFS_OAUTH_MANUAL_DONE_BUTTON, 1, GetString(MSG_PREFS_OAUTH_MANUAL_DONE_BUTTON_HELP))),
				MUIA_Group_Child, (IPTR)EmptyRectangle(100),
			TAG_END),
		TAG_END)),
	TAG_MORE, (IPTR)msg->ops_AttrList);

	if(obj && mod_data)
	{
		struct OAuthGroupData *d = INST_DATA(cl, obj);

		DoMethod(key_button, MUIM_Notify, MUIA_Pressed, FALSE, (IPTR)obj, 1,
		 OAGM_OpenAuthURL);

		DoMethod(manual_button, MUIM_Notify, MUIA_Pressed, FALSE, (IPTR)manual_group, 3,
		 MUIM_Set, MUIA_ShowMe, TRUE);

		DoMethod(manual_button, MUIM_Notify, MUIA_Pressed, FALSE, (IPTR)auth_buttons_group, 3,
		 MUIM_Set, MUIA_ShowMe, FALSE);

		DoMethod(manual_done_button, MUIM_Notify, MUIA_Pressed, FALSE, (IPTR)obj, 2,
		 OAGM_FetchTokens, (IPTR)xget(manual_code_string, MUIA_String_Contents));

		DoMethod(rem_authorization_button, MUIM_Notify, MUIA_Pressed, FALSE, (IPTR)obj, 1,
		 OAGM_RemoveAuthorization);

		d->oagd_ModuleData = mod_data;
		d->oagd_AuthorizedText = atext;
		d->oagd_ManualGroup = manual_group;
		d->oagd_AuthButtonsGroup = auth_buttons_group;
		d->oagd_RemAuthGroup = rem_authorization_group;

		return (IPTR)obj;
	}

	CoerceMethod(cl, obj, OM_DISPOSE);
	return (IPTR)NULL;
}

static IPTR OAuthGroupGet(Class *cl, Object *obj, struct opGet *msg)
{
	struct OAuthGroupData *d = INST_DATA(cl, obj);
	int rv = FALSE;

	switch(msg->opg_AttrID)
	{
		case OAGA_AuthToken:
			*msg->opg_Storage = (ULONG)d->oagd_AuthToken;
		return TRUE;

		case OAGA_RefreshToken:
			*msg->opg_Storage = (ULONG)d->oagd_RefreshToken;
		return TRUE;

		default: rv = (DoSuperMethodA(cl, obj, (Msg)msg));
	}

	return rv;
}

static IPTR OAuthGroupSet(Class *cl, Object *obj, struct opSet *msg)
{
	struct OAuthGroupData *d = INST_DATA(cl, obj);
	int tagcount = 0;
	struct TagItem *tag, *tagptr = msg->ops_AttrList;

	while((tag = NextTagItem(&tagptr)))
	{
		switch(tag->ti_Tag)
		{
			case OAGA_AuthToken:
				if(tag->ti_Data)
				{
					if(d->oagd_AuthToken)
						StrFree(d->oagd_AuthToken);
					d->oagd_AuthToken = StrNew((STRPTR)tag->ti_Data);
				}
				tagcount++;
			break;
		}
	}

	tagcount += DoSuperMethodA(cl, obj, (Msg)msg);
	return tagcount;
}

static IPTR OAuthGroupDispose(Class *cl, Object *obj, Msg msg)
{
	struct OAuthGroupData *d = INST_DATA(cl, obj);

	if(d->oagd_AuthToken)
		StrFree(d->oagd_AuthToken);

	if(d->oagd_RefreshToken)
		StrFree(d->oagd_RefreshToken);

	return DoSuperMethodA(cl, obj, msg);
}

static IPTR OAuthGroupOpenAuthURL(Class *cl, Object *obj)
{
	struct OAuthGroupData *d = INST_DATA(cl, obj);

	URL_OpenA(GOOGLE_AUTH_URL, NULL);

	d->oagd_ModuleData->EnumerateWindows = TRUE;
	d->oagd_ModuleData->FiveMinutes = 60 * 5;

	return (IPTR)0;
}

static IPTR OAuthGroupFetchTokens(Class *cl, Object *obj, struct OAGP_FetchTokens *msg)
{
	struct OAuthGroupData *d = INST_DATA(cl, obj);
	ENTER();

	if(msg->AuthKey && *msg->AuthKey != 0x00)
	{
		STRPTR token, refresh_token;

		set(_app(obj), MUIA_Application_Sleep, TRUE);

		if(iks_google_fetch_token(msg->AuthKey, GOOGLE_CLIENT_ID, GOOGLE_CLIENT_SECRET, (char**)&token, (char**)&refresh_token) == 0)
		{
			if(token)
			{
				d->oagd_AuthToken = StrNew(token);
				iks_free(token);
			}
			if(refresh_token)
			{
				d->oagd_RefreshToken = StrNew(refresh_token);
				iks_free(refresh_token);
			}
		}

		set(_app(obj), MUIA_Application_Sleep, FALSE);
	}

	if(!d->oagd_AuthToken || !d->oagd_RefreshToken)
		MUI_RequestA(_app(obj), _win(obj), 0x00, GetString(MSG_OAUTH_ERROR), GetString(MSG_OAUTH_ERROR_GADGETS), GetString(MSG_OAUTH_ERROR_MSG), NULL);
	else
	{
		set(d->oagd_RemAuthGroup, MUIA_ShowMe, TRUE);
		set(d->oagd_AuthorizedText, MUIA_ShowMe, TRUE);
		set(d->oagd_ManualGroup, MUIA_ShowMe, FALSE);
		set(d->oagd_AuthButtonsGroup, MUIA_ShowMe, FALSE);
	}

	LEAVE();
	return (IPTR)0;
}

static IPTR OAuthGroupExport(Class *cl, Object *obj, struct MUIP_Export *msg)
{
	struct OAuthGroupData *d = INST_DATA(cl, obj);

	if(d->oagd_AuthToken)
		DoMethod(msg->dataspace, MUIM_Dataspace_Add, (IPTR)d->oagd_AuthToken, StrLen(d->oagd_AuthToken) + 1, USD_PREFS_OAUTH_ATOKEN);
	else
		DoMethod(msg->dataspace, MUIM_Dataspace_Add, (IPTR)"", 1, USD_PREFS_OAUTH_ATOKEN);

	if(d->oagd_RefreshToken)
		DoMethod(msg->dataspace, MUIM_Dataspace_Add, (IPTR)d->oagd_RefreshToken, StrLen(d->oagd_RefreshToken) + 1, USD_PREFS_OAUTH_RTOKEN);
	else
		DoMethod(msg->dataspace, MUIM_Dataspace_Add, (IPTR)"", 1, USD_PREFS_OAUTH_RTOKEN);

	return (IPTR)0;
}

static IPTR OAuthGroupImport(Class *cl, Object *obj, struct MUIP_Import *msg)
{
	struct OAuthGroupData *d = INST_DATA(cl, obj);
	STRPTR at, rt;

	if((at = (STRPTR)DoMethod(msg->dataspace, MUIM_Dataspace_Find, USD_PREFS_OAUTH_ATOKEN)))
	{
		if((rt = (STRPTR)DoMethod(msg->dataspace, MUIM_Dataspace_Find, USD_PREFS_OAUTH_RTOKEN)))
		{
			d->oagd_AuthToken = StrNew(at);
			d->oagd_RefreshToken = StrNew(rt);
		}
	}

	if(d->oagd_AuthToken && d->oagd_RefreshToken)
	{
		set(d->oagd_AuthButtonsGroup, MUIA_ShowMe, FALSE);
		set(d->oagd_AuthorizedText, MUIA_ShowMe, TRUE);
		set(d->oagd_RemAuthGroup, MUIA_ShowMe, TRUE);
	}
	return (IPTR)0;
}

static IPTR OAuthGroupRemoveAuthorization(Class *cl, Object *obj)
{
	struct OAuthGroupData *d = INST_DATA(cl, obj);

	if(d->oagd_AuthToken)
	{
		StrFree(d->oagd_AuthToken);
		d->oagd_AuthToken = NULL;
	}

	if(d->oagd_RefreshToken)
	{
		StrFree(d->oagd_RefreshToken);
		d->oagd_RefreshToken = NULL;
	}

	set(d->oagd_RemAuthGroup, MUIA_ShowMe, FALSE);
	set(d->oagd_AuthorizedText, MUIA_ShowMe, FALSE);
	set(d->oagd_ManualGroup, MUIA_ShowMe, FALSE);
	set(d->oagd_AuthButtonsGroup, MUIA_ShowMe, TRUE);

	return (IPTR)0;
}

static IPTR OAuthGroupDispatcher(VOID)
{
	Class *cl = (Class*)REG_A0;
	Object *obj = (Object*)REG_A2;
	Msg msg = (Msg)REG_A1;

	switch(msg->MethodID)
	{
		case OM_NEW:                    return(OAuthGroupNew(cl, obj, (struct opSet*) msg));
		case OM_GET:                    return (OAuthGroupGet(cl, obj, (struct opGet*)msg));
		case OM_SET:                    return (OAuthGroupSet(cl, obj, (struct opSet*)msg));
		case OM_DISPOSE:                return(OAuthGroupDispose(cl, obj, msg));
		case OAGM_OpenAuthURL:          return(OAuthGroupOpenAuthURL(cl, obj));
		case OAGM_FetchTokens:          return(OAuthGroupFetchTokens(cl, obj, (struct OAGP_FetchTokens*)msg));
		case OAGM_RemoveAuthorization:  return(OAuthGroupRemoveAuthorization(cl, obj));
		case MUIM_Export:               return(OAuthGroupExport(cl, obj, (struct MUIP_Export*)msg));
		case MUIM_Import:               return(OAuthGroupImport(cl, obj, (struct MUIP_Import*)msg));
		default:                        return (DoSuperMethodA(cl, obj, msg));
	}
}
