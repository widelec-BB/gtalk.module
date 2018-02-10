/*
 * Copyright (c) 2015 - 2018 Filip "widelec" Maryjanski, BlaBla group.
 * All rights reserved.
 * Distributed under the terms of the GNU Lesser General Public License v2.1.
 */

#ifndef __GLOBALDEFINES_H__
#define __GLOBALDEFINES_H__

#define CLASSNAME "gtalk.module"
#define VERSION 1
#define REVISION 2
#define DATE __AMIGADATE__
#define VERS "gtalk.module 1.2"
#define AUTHOR "Filip \"widelec\" Maryjañski"
#define DESC "GTalk Module for KwaKwa"
#define COPYRIGHT "© " "2015 - 2018" " " AUTHOR
#define VSTRING VERS DATE COPYRIGHT
#define VERSTAG "\0$VER: " VSTRING
#define RELEASE_TAG "F1"
#define PROTOCOL_NAME "Google Talk"
#define MODULE_ID 0x02000000

#ifdef MAKE_ID
#undef MAKE_ID
#endif /* MAKE_ID */

#define MAKE_ID(x) (MODULE_ID | (x))

#define GOOGLE_CLIENT_ID "645637237586-f45ffocvt7p00dfk20r52ul8rl8gd2mf.apps.googleusercontent.com"
#define GOOGLE_CLIENT_SECRET "9b8v4Z4sxuFJLVep5e28P0pa"
#define GOOGLE_AUTH_URL "https://accounts.google.com/o/oauth2/auth?scope=https://www.googleapis.com/auth/googletalk&redirect_uri=urn:ietf:wg:oauth:2.0:oob:auto&response_type=code&client_id="GOOGLE_CLIENT_ID

#ifdef __DEBUG__
#include <clib/debug_protos.h>
#define tprintf(template, ...) KPrintF((CONST_STRPTR)CLASSNAME " " __FILE__ " %d: " template, __LINE__ , ##__VA_ARGS__)
#define ENTER(...) KPrintF((CONST_STRPTR)CLASSNAME " enters: %s\n", __PRETTY_FUNCTION__)
#define LEAVE(...) KPrintF((CONST_STRPTR)CLASSNAME " leaves: %s\n", __PRETTY_FUNCTION__)
#define strd(x)((STRPTR)x ? (STRPTR)x : (STRPTR)"NULL")
#else
#define tprintf(...)
#define ENTER(...)
#define LEAVE(...)
#endif /* __DEBUG__ */

#define UNUSED __attribute__((unused))

#define CACHE_DIR "PROGDIR:cache/gtalk.module/"
#define CACHE_AVATARS_DIR CACHE_DIR "avatars/"

#endif /* __GLOBALDEFINES_H__ */
