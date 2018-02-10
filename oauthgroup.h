/*
 * Copyright (c) 2015 - 2018 Filip "widelec" Maryjanski, BlaBla group.
 * All rights reserved.
 * Distributed under the terms of the GNU Lesser General Public License v2.1.
 */

#ifndef __OAUTHGROUP_H__
#define __OAUTHGROUP_H__

#include <proto/intuition.h>
#include <proto/utility.h>
#include <proto/muimaster.h>
#include <clib/alib_protos.h>
#include "gui.h"

extern struct MUI_CustomClass *OAuthGroupClass;

struct MUI_CustomClass *CreateOAuthGroupClass(VOID);
VOID DeleteOAuthGroupClass(VOID);

#define USD_PREFS_OAUTH_KEY_BUTTON                          MAKE_ID(0x5000)
#define USD_PREFS_OAUTH_KEY_MANUAL_BUTTON                   MAKE_ID(0x5001)
#define USD_PREFS_OAUTH_MANUAL_DONE_BUTTON                  MAKE_ID(0x5002)
#define USD_PREFS_OAUTH_REMOVE_BUTTON                       MAKE_ID(0x5003)

#define OAGM_OpenAuthURL                                    MAKE_ID(0x5100)
#define OAGM_FetchTokens                                    MAKE_ID(0x5101)
#define OAGM_RemoveAuthorization                            MAKE_ID(0x5102)

#define OAGA_ModuleObjectData                               MAKE_ID(0x5400) /* [i..] struct ObjectData* */
#define OAGA_AuthToken                                      MAKE_ID(0x5401) /* [.sg] CONST_STRPTR */
#define OAGA_RefreshToken                                   MAKE_ID(0x5402) /* [..g] CONST_STRPTR */

#define USD_PREFS_OAUTH_ATOKEN                              MAKE_ID(0x5FFE) /* no gadget, used for storing configuration via MUIC_Dataspace */
#define USD_PREFS_OAUTH_RTOKEN                              MAKE_ID(0x5FFF) /* no gadget, used for storing configuration via MUIC_Dataspace */

struct OAGP_FetchTokens {ULONG MethodID; STRPTR AuthKey;};

#endif /* __OAUTHGROUP_H__ */
