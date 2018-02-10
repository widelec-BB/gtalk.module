/*
 * Copyright (c) 2015 - 2018 Filip "widelec" Maryjanski, BlaBla group.
 * All rights reserved.
 * Distributed under the terms of the GNU Lesser General Public License v2.1.
 */

#ifndef __GUI_H__
#define __GUI_H__

#include <proto/intuition.h>
#include <proto/muimaster.h>
#include <clib/alib_protos.h>
#include "globaldefines.h"
#include "class.h"
#include "oauthgroup.h"

#define USD_PREFS_BASIC_ID_STRING            MAKE_ID(0x00000000)
#define USD_PREFS_OAUTH_GROUP                MAKE_ID(0x00000001)
#define USD_PREFS_ADDONS_GMAIL_NOTIFY        MAKE_ID(0x00000002) /* deprecated - google disabled this function, so this ID is actually not used */
#define USD_PREFS_ADDONS_FETCH_ROSTER        MAKE_ID(0x00000003)

extern struct Library *IntuitionBase;

Object *CreatePrefsPage(struct ObjData *d);
Object* MUI_NewObjectM(char *classname, ...);
#define findobj(id, parent) (Object*)DoMethod(parent, MUIM_FindUData, id)
#define EmptyRectangle(weight) MUI_NewObjectM(MUIC_Rectangle, MUIA_Weight, weight, TAG_END)

static inline ULONG xget(Object *obj, ULONG att)
{
  ULONG result;

  GetAttr(att, obj, &result);
  return result;
}

static inline Object* StringLabel(STRPTR label, STRPTR preparse)
{
	Object *obj = MUI_NewObjectM(MUIC_Text,
		MUIA_FramePhantomHoriz, TRUE,
		MUIA_Frame, MUIV_Frame_String,
		MUIA_Text_PreParse, (IPTR)preparse,
		MUIA_Text_Contents, (IPTR)label,
		MUIA_HorizWeight, 0,
	TAG_END);

	return obj;
}

static inline Object* StringGadget(ULONG id)
{
	Object *obj = MUI_NewObjectM(MUIC_String,
		MUIA_UserData, id,
		MUIA_ObjectID, id,
		MUIA_Frame, MUIV_Frame_String,
		MUIA_Background, MUII_StringBack,
		MUIA_CycleChain, TRUE,
		MUIA_String_AdvanceOnCR, TRUE,
	TAG_END);

	return obj;
}

static inline Object* GfxButton(ULONG id, STRPTR pic, UBYTE control)
{
	Object *obj = MUI_NewObjectM(MUIC_Group,
		MUIA_InputMode, MUIV_InputMode_RelVerify,
		MUIA_UserData, id,
		MUIA_ObjectID, id,
		MUIA_ControlChar, (IPTR)control,
		MUIA_Group_Child, (IPTR)MUI_NewObjectM(MUIC_Dtpic,
			MUIA_Dtpic_Name, (IPTR)pic,
		TAG_END),
	TAG_END);

	return obj;
}

static inline Object* NormalButton(STRPTR label, UBYTE control, LONG objid, ULONG weight, STRPTR help)
{
	Object *obj = MUI_NewObjectM(MUIC_Text,
		MUIA_Text_Contents, (IPTR)label,
		MUIA_Text_PreParse, (IPTR)"\33c",
		MUIA_Frame, MUIV_Frame_Button,
		MUIA_Background, MUII_ButtonBack,
		MUIA_Font, MUIV_Font_Button,
		MUIA_InputMode, MUIV_InputMode_RelVerify,
		MUIA_Text_HiChar, (IPTR)control,
		MUIA_ControlChar, (IPTR)control,
		MUIA_CycleChain, TRUE,
		MUIA_HorizWeight, weight,
		MUIA_UserData, objid,
		MUIA_ShortHelp, help,
	TAG_END);

	return obj;
}

#endif /* __GUI_H__ */
