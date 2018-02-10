/*
 * Copyright (c) 2015 - 2018 Filip "widelec" Maryjanski, BlaBla group.
 * All rights reserved.
 * Distributed under the terms of the GNU Lesser General Public License v2.1.
 */

#include <proto/muimaster.h>
#include <proto/alib.h>
#include "globaldefines.h"
#include "gui.h"
#include "locale.h"

extern struct Library *MUIMasterBase, *IntuitionBase;

Object* MUI_NewObjectM(char *classname, ...)
{
	va_list args, args2;
	LONG argc = 0;
	ULONG tag;
	Object *result = NULL;

	__va_copy(args2, args);

	va_start(args, classname);

	while((tag = va_arg(args, ULONG)) != TAG_END)
	{
		va_arg(args, IPTR);
		argc++;
	}

	va_end(args);

	{
		struct TagItem tags[argc + 1];  // one for {TAG_END, 0}
		LONG i;

		va_start(args2, classname);

		for (i = 0; i < argc; i++)
		{
			tags[i].ti_Tag = va_arg(args2, ULONG);
			tags[i].ti_Data = va_arg(args2, IPTR);
		}

		tags[argc].ti_Tag = TAG_END;
		tags[argc].ti_Data = 0;

		va_end(args2);

		result = (Object*)MUI_NewObjectA(classname, tags);
	}
	return result;
}

Object *CreatePrefsPage(struct ObjData *d)
{
	Object *result;
	Object *login_group, *addons;
	ENTER();

	login_group = MUI_NewObjectM(MUIC_Group,
		MUIA_Frame, MUIV_Frame_Group,
		MUIA_FrameTitle, (IPTR)GetString(MSG_PREFS_BASIC),
		MUIA_Background, MUII_GroupBack,
		MUIA_Group_Columns, 2,
		MUIA_Group_Child, (IPTR)StringLabel(GetString(MSG_PREFS_BASIC_ID), "\33r"),
		MUIA_Group_Child, (IPTR)MUI_NewObjectM(MUIC_String,
			MUIA_ObjectID, USD_PREFS_BASIC_ID_STRING,
			MUIA_UserData, USD_PREFS_BASIC_ID_STRING,
			MUIA_Frame, MUIV_Frame_String,
			MUIA_Background, MUII_StringBack,
			MUIA_CycleChain, TRUE,
			MUIA_String_AdvanceOnCR, TRUE,
			MUIA_ShortHelp, (IPTR)GetString(MSG_PREFS_BASIC_ID_HELP),
		TAG_END),
	TAG_END);

	addons = MUI_NewObjectM(MUIC_Group,
		MUIA_Frame, MUIV_Frame_Group,
		MUIA_FrameTitle, (IPTR)GetString(MSG_PREFS_ADDONS_TITLE),
		MUIA_Background, MUII_GroupBack,
		MUIA_Group_Child, (IPTR)MUI_NewObjectM(MUIC_Group,
			MUIA_Group_Horiz, TRUE,
			MUIA_Group_Child, (IPTR)MUI_NewObjectM(MUIC_Image,
				MUIA_ObjectID, USD_PREFS_ADDONS_FETCH_ROSTER,
				MUIA_UserData, USD_PREFS_ADDONS_FETCH_ROSTER,
				MUIA_Image_Spec, (IPTR)"6:15",
				MUIA_ShowSelState, FALSE,
				MUIA_Selected, TRUE,
				MUIA_InputMode, MUIV_InputMode_Toggle,
				MUIA_CycleChain, TRUE,
				MUIA_ShortHelp, (IPTR)GetString(MSG_PREFS_ADDONS_FETCH_ROSTER_HELP),
			TAG_END),
			MUIA_Group_Child, (IPTR)StringLabel(GetString(MSG_PREFS_ADDONS_FETCH_ROSTER), "\33r"),
			MUIA_Group_Child, (IPTR)EmptyRectangle(100),
		TAG_END),
	TAG_END);

	result = MUI_NewObjectM(MUIC_Group,
		MUIA_Group_Child, (IPTR)EmptyRectangle(100),
		MUIA_Group_Child, (IPTR)login_group,
		MUIA_Group_Child, (IPTR)NewObject(OAuthGroupClass->mcc_Class, NULL,
			MUIA_ObjectID, USD_PREFS_OAUTH_GROUP,
			MUIA_UserData, USD_PREFS_OAUTH_GROUP,
			OAGA_ModuleObjectData, (IPTR)d,
		TAG_END),
		MUIA_Group_Child, (IPTR)addons,
		MUIA_Group_Child, (IPTR)EmptyRectangle(100),
	TAG_END);

	LEAVE();
	return result;
}
