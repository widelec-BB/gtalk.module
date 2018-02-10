/*
 * Copyright (c) 2015 - 2018 Filip "widelec" Maryjanski, BlaBla group.
 * All rights reserved.
 * Distributed under the terms of the GNU Lesser General Public License v2.1.
 */

#ifndef TRANSLATIONS_H
#define TRANSLATIONS_H 1

/* Locale Catalog Source File
 *
 * Automatically created by SimpleCat V3
 * Do NOT edit by hand!
 *
 * SimpleCat ©1992-2012 Guido Mersmann
 *
 */



/****************************************************************************/


#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifdef CATCOMP_ARRAY
#undef CATCOMP_NUMBERS
#undef CATCOMP_STRINGS
#define CATCOMP_NUMBERS
#define CATCOMP_STRINGS
#endif

#ifdef CATCOMP_BLOCK
#undef CATCOMP_STRINGS
#define CATCOMP_STRINGS
#endif



/****************************************************************************/


#ifdef CATCOMP_NUMBERS

#define MSG_PREFS_BASIC 0
#define MSG_PREFS_BASIC_ID 1
#define MSG_PREFS_BASIC_ID_HELP 2
#define MSG_PREFS_OAUTH 3
#define MSG_PREFS_OAUTH_EXPLANATION 4
#define MSG_PREFS_OAUTH_AUTHORIZED 5
#define MSG_PREFS_OAUTH_KEY_BUTTON 6
#define MSG_PREFS_OAUTH_KEY_BUTTON_HOTKEY 7
#define MSG_PREFS_OAUTH_KEY_BUTTON_HELP 8
#define MSG_PREFS_OAUTH_KEY_MANUAL_BUTTON 9
#define MSG_PREFS_OAUTH_KEY_MANUAL_HOTKEY 10
#define MSG_PREFS_OAUTH_KEY_MANUAL_BUTTON_HELP 11
#define MSG_OAUTH_ERROR 12
#define MSG_OAUTH_ERROR_GADGETS 13
#define MSG_OAUTH_ERROR_MSG 14
#define MSG_ERROR_UNSUPPORTED_AUTH_METHOD 15
#define MSG_BEACON_NEW_MAIL 16
#define MSG_PREFS_ADDONS_TITLE 17
#define MSG_PREFS_ADDONS_GMAIL_NOTIFICATIONS 18
#define MSG_PREFS_ADDONS_GMAIL_NOTIFICATIONS_HELP 19
#define MSG_PREFS_ADDONS_FETCH_ROSTER 20
#define MSG_PREFS_ADDONS_FETCH_ROSTER_HELP 21
#define MSG_PREFS_OAUTH_MANUAL_TOKEN_TITLE 22
#define MSG_PREFS_OAUTH_MANUAL_TOKEN_HELP 23
#define MSG_PREFS_OAUTH_MANUAL_URL_TITLE 24
#define MSG_PREFS_OAUTH_MANUAL_URL_HELP 25
#define MSG_PREFS_OAUTH_MANUAL_DONE_BUTTON 26
#define MSG_PREFS_OAUTH_MANUAL_DONE_BUTTON_HELP 27
#define MSG_PREFS_OAUTH_REMOVE_BUTTON 28
#define MSG_PREFS_OAUTH_REMOVE_BUTTON_HOTKEY 29
#define MSG_PREFS_OAUTH_REMOVE_BUTTON_HELP 30

#define CATCOMP_LASTID 30

#endif /* CATCOMP_NUMBERS */


/****************************************************************************/


#ifdef CATCOMP_STRINGS

#define MSG_PREFS_BASIC_STR "User Settings"
#define MSG_PREFS_BASIC_ID_STR "User name:"
#define MSG_PREFS_BASIC_ID_HELP_STR "Your Google Talk user name, with or without \"@gmail.com\"."
#define MSG_PREFS_OAUTH_STR "OAuth"
#define MSG_PREFS_OAUTH_EXPLANATION_STR "To connect go GTalk, you must give KwaKwa permission. A web browser window will be shown when you click \"Allow Access...\" button. If you encounter any problems with automatic authorization you can click \"Allow Access Manually...\" button to start manual authorization. You will be asked to go to specific URL, log into your Google Account and copy authorization code to KwaKwa. Code will be displayed at web browser window's title bar and prefixed with \"Success code=\"."
#define MSG_PREFS_OAUTH_AUTHORIZED_STR "KwaKwa is authorized for GTalk."
#define MSG_PREFS_OAUTH_KEY_BUTTON_STR "Allow Access..."
#define MSG_PREFS_OAUTH_KEY_BUTTON_HOTKEY_STR "A"
#define MSG_PREFS_OAUTH_KEY_BUTTON_HELP_STR "Press this button to start authorization. You will be redirected to web browser where you can allow KwaKwa to access your GTalk account."
#define MSG_PREFS_OAUTH_KEY_MANUAL_BUTTON_STR "Allow Access Manually..."
#define MSG_PREFS_OAUTH_KEY_MANUAL_HOTKEY_STR "m"
#define MSG_PREFS_OAUTH_KEY_MANUAL_BUTTON_HELP_STR "If you encounter any problems with automatic authorization you can press this button to start manual authorization."
#define MSG_OAUTH_ERROR_STR "Error!"
#define MSG_OAUTH_ERROR_GADGETS_STR "*_OK"
#define MSG_OAUTH_ERROR_MSG_STR "There was an error during authorization process. Please, try again."
#define MSG_ERROR_UNSUPPORTED_AUTH_METHOD_STR "Unsupported authorization method."
#define MSG_BEACON_NEW_MAIL_STR "You have new mail."
#define MSG_PREFS_ADDONS_TITLE_STR "Additional settings"
#define MSG_PREFS_ADDONS_GMAIL_NOTIFICATIONS_STR "Notify about new e-mails in GMail."
#define MSG_PREFS_ADDONS_GMAIL_NOTIFICATIONS_HELP_STR "Check if you want to be notified (by MagicBeacon) about new unread messages in your GMail inbox. This option affect only new connections."
#define MSG_PREFS_ADDONS_FETCH_ROSTER_STR "Fetch contacts if contacts list is empty."
#define MSG_PREFS_ADDONS_FETCH_ROSTER_HELP_STR "If contacts list is empty fetch automatically contacts list from server."
#define MSG_PREFS_OAUTH_MANUAL_TOKEN_TITLE_STR "Authorization Code:Success code="
#define MSG_PREFS_OAUTH_MANUAL_TOKEN_HELP_STR "Please paste here authorization code provided by Google."
#define MSG_PREFS_OAUTH_MANUAL_URL_TITLE_STR "Authorization URL:"
#define MSG_PREFS_OAUTH_MANUAL_URL_HELP_STR "Please go to this URL and allow KwaKwa to acces your Google Account."
#define MSG_PREFS_OAUTH_MANUAL_DONE_BUTTON_STR "Allow access"
#define MSG_PREFS_OAUTH_MANUAL_DONE_BUTTON_HELP_STR "Click when authorization token is ready."
#define MSG_PREFS_OAUTH_REMOVE_BUTTON_STR "Reauthenticate"
#define MSG_PREFS_OAUTH_REMOVE_BUTTON_HOTKEY_STR "R"
#define MSG_PREFS_OAUTH_REMOVE_BUTTON_HELP_STR "Press to remove stored authorization data."

#endif /* CATCOMP_STRINGS */


/****************************************************************************/


#ifdef CATCOMP_ARRAY

struct CatCompArrayType
{
    LONG   cca_ID;
    STRPTR cca_Str;
};

static const struct CatCompArrayType CatCompArray[] =
{
    {MSG_PREFS_BASIC,(STRPTR)MSG_PREFS_BASIC_STR},
    {MSG_PREFS_BASIC_ID,(STRPTR)MSG_PREFS_BASIC_ID_STR},
    {MSG_PREFS_BASIC_ID_HELP,(STRPTR)MSG_PREFS_BASIC_ID_HELP_STR},
    {MSG_PREFS_OAUTH,(STRPTR)MSG_PREFS_OAUTH_STR},
    {MSG_PREFS_OAUTH_EXPLANATION,(STRPTR)MSG_PREFS_OAUTH_EXPLANATION_STR},
    {MSG_PREFS_OAUTH_AUTHORIZED,(STRPTR)MSG_PREFS_OAUTH_AUTHORIZED_STR},
    {MSG_PREFS_OAUTH_KEY_BUTTON,(STRPTR)MSG_PREFS_OAUTH_KEY_BUTTON_STR},
    {MSG_PREFS_OAUTH_KEY_BUTTON_HOTKEY,(STRPTR)MSG_PREFS_OAUTH_KEY_BUTTON_HOTKEY_STR},
    {MSG_PREFS_OAUTH_KEY_BUTTON_HELP,(STRPTR)MSG_PREFS_OAUTH_KEY_BUTTON_HELP_STR},
    {MSG_PREFS_OAUTH_KEY_MANUAL_BUTTON,(STRPTR)MSG_PREFS_OAUTH_KEY_MANUAL_BUTTON_STR},
    {MSG_PREFS_OAUTH_KEY_MANUAL_HOTKEY,(STRPTR)MSG_PREFS_OAUTH_KEY_MANUAL_HOTKEY_STR},
    {MSG_PREFS_OAUTH_KEY_MANUAL_BUTTON_HELP,(STRPTR)MSG_PREFS_OAUTH_KEY_MANUAL_BUTTON_HELP_STR},
    {MSG_OAUTH_ERROR,(STRPTR)MSG_OAUTH_ERROR_STR},
    {MSG_OAUTH_ERROR_GADGETS,(STRPTR)MSG_OAUTH_ERROR_GADGETS_STR},
    {MSG_OAUTH_ERROR_MSG,(STRPTR)MSG_OAUTH_ERROR_MSG_STR},
    {MSG_ERROR_UNSUPPORTED_AUTH_METHOD,(STRPTR)MSG_ERROR_UNSUPPORTED_AUTH_METHOD_STR},
    {MSG_BEACON_NEW_MAIL,(STRPTR)MSG_BEACON_NEW_MAIL_STR},
    {MSG_PREFS_ADDONS_TITLE,(STRPTR)MSG_PREFS_ADDONS_TITLE_STR},
    {MSG_PREFS_ADDONS_GMAIL_NOTIFICATIONS,(STRPTR)MSG_PREFS_ADDONS_GMAIL_NOTIFICATIONS_STR},
    {MSG_PREFS_ADDONS_GMAIL_NOTIFICATIONS_HELP,(STRPTR)MSG_PREFS_ADDONS_GMAIL_NOTIFICATIONS_HELP_STR},
    {MSG_PREFS_ADDONS_FETCH_ROSTER,(STRPTR)MSG_PREFS_ADDONS_FETCH_ROSTER_STR},
    {MSG_PREFS_ADDONS_FETCH_ROSTER_HELP,(STRPTR)MSG_PREFS_ADDONS_FETCH_ROSTER_HELP_STR},
    {MSG_PREFS_OAUTH_MANUAL_TOKEN_TITLE,(STRPTR)MSG_PREFS_OAUTH_MANUAL_TOKEN_TITLE_STR},
    {MSG_PREFS_OAUTH_MANUAL_TOKEN_HELP,(STRPTR)MSG_PREFS_OAUTH_MANUAL_TOKEN_HELP_STR},
    {MSG_PREFS_OAUTH_MANUAL_URL_TITLE,(STRPTR)MSG_PREFS_OAUTH_MANUAL_URL_TITLE_STR},
    {MSG_PREFS_OAUTH_MANUAL_URL_HELP,(STRPTR)MSG_PREFS_OAUTH_MANUAL_URL_HELP_STR},
    {MSG_PREFS_OAUTH_MANUAL_DONE_BUTTON,(STRPTR)MSG_PREFS_OAUTH_MANUAL_DONE_BUTTON_STR},
    {MSG_PREFS_OAUTH_MANUAL_DONE_BUTTON_HELP,(STRPTR)MSG_PREFS_OAUTH_MANUAL_DONE_BUTTON_HELP_STR},
    {MSG_PREFS_OAUTH_REMOVE_BUTTON,(STRPTR)MSG_PREFS_OAUTH_REMOVE_BUTTON_STR},
    {MSG_PREFS_OAUTH_REMOVE_BUTTON_HOTKEY,(STRPTR)MSG_PREFS_OAUTH_REMOVE_BUTTON_HOTKEY_STR},
    {MSG_PREFS_OAUTH_REMOVE_BUTTON_HELP,(STRPTR)MSG_PREFS_OAUTH_REMOVE_BUTTON_HELP_STR},
};

#endif /* CATCOMP_ARRAY */


/****************************************************************************/


#ifdef CATCOMP_BLOCK

static const char CatCompBlock[] =
{
    "\x00\x00\x00\x00\x00\x0E"
    MSG_PREFS_BASIC_STR "\x00"
    "\x00\x00\x00\x01\x00\x0C"
    MSG_PREFS_BASIC_ID_STR "\x00\x00"
    "\x00\x00\x00\x02\x00\x3A"
    MSG_PREFS_BASIC_ID_HELP_STR "\x00"
    "\x00\x00\x00\x03\x00\x06"
    MSG_PREFS_OAUTH_STR "\x00"
    "\x00\x00\x00\x04\x01\xD6"
    MSG_PREFS_OAUTH_EXPLANATION_STR "\x00\x00"
    "\x00\x00\x00\x05\x00\x20"
    MSG_PREFS_OAUTH_AUTHORIZED_STR "\x00"
    "\x00\x00\x00\x06\x00\x10"
    MSG_PREFS_OAUTH_KEY_BUTTON_STR "\x00"
    "\x00\x00\x00\x07\x00\x02"
    MSG_PREFS_OAUTH_KEY_BUTTON_HOTKEY_STR "\x00"
    "\x00\x00\x00\x08\x00\x8A"
    MSG_PREFS_OAUTH_KEY_BUTTON_HELP_STR "\x00\x00"
    "\x00\x00\x00\x09\x00\x1A"
    MSG_PREFS_OAUTH_KEY_MANUAL_BUTTON_STR "\x00\x00"
    "\x00\x00\x00\x0A\x00\x02"
    MSG_PREFS_OAUTH_KEY_MANUAL_HOTKEY_STR "\x00"
    "\x00\x00\x00\x0B\x00\x74"
    MSG_PREFS_OAUTH_KEY_MANUAL_BUTTON_HELP_STR "\x00"
    "\x00\x00\x00\x0C\x00\x08"
    MSG_OAUTH_ERROR_STR "\x00\x00"
    "\x00\x00\x00\x0D\x00\x06"
    MSG_OAUTH_ERROR_GADGETS_STR "\x00\x00"
    "\x00\x00\x00\x0E\x00\x44"
    MSG_OAUTH_ERROR_MSG_STR "\x00"
    "\x00\x00\x00\x0F\x00\x22"
    MSG_ERROR_UNSUPPORTED_AUTH_METHOD_STR "\x00"
    "\x00\x00\x00\x10\x00\x14"
    MSG_BEACON_NEW_MAIL_STR "\x00\x00"
    "\x00\x00\x00\x11\x00\x14"
    MSG_PREFS_ADDONS_TITLE_STR "\x00"
    "\x00\x00\x00\x12\x00\x24"
    MSG_PREFS_ADDONS_GMAIL_NOTIFICATIONS_STR "\x00\x00"
    "\x00\x00\x00\x13\x00\x8A"
    MSG_PREFS_ADDONS_GMAIL_NOTIFICATIONS_HELP_STR "\x00"
    "\x00\x00\x00\x14\x00\x2A"
    MSG_PREFS_ADDONS_FETCH_ROSTER_STR "\x00"
    "\x00\x00\x00\x15\x00\x4A"
    MSG_PREFS_ADDONS_FETCH_ROSTER_HELP_STR "\x00\x00"
    "\x00\x00\x00\x16\x00\x22"
    MSG_PREFS_OAUTH_MANUAL_TOKEN_TITLE_STR "\x00\x00"
    "\x00\x00\x00\x17\x00\x3A"
    MSG_PREFS_OAUTH_MANUAL_TOKEN_HELP_STR "\x00\x00"
    "\x00\x00\x00\x18\x00\x14"
    MSG_PREFS_OAUTH_MANUAL_URL_TITLE_STR "\x00\x00"
    "\x00\x00\x00\x19\x00\x46"
    MSG_PREFS_OAUTH_MANUAL_URL_HELP_STR "\x00\x00"
    "\x00\x00\x00\x1A\x00\x0E"
    MSG_PREFS_OAUTH_MANUAL_DONE_BUTTON_STR "\x00\x00"
    "\x00\x00\x00\x1B\x00\x2A"
    MSG_PREFS_OAUTH_MANUAL_DONE_BUTTON_HELP_STR "\x00\x00"
    "\x00\x00\x00\x1C\x00\x10"
    MSG_PREFS_OAUTH_REMOVE_BUTTON_STR "\x00\x00"
    "\x00\x00\x00\x1D\x00\x02"
    MSG_PREFS_OAUTH_REMOVE_BUTTON_HOTKEY_STR "\x00"
    "\x00\x00\x00\x1E\x00\x2C"
    MSG_PREFS_OAUTH_REMOVE_BUTTON_HELP_STR "\x00\x00"
};

#endif /* CATCOMP_BLOCK */


/****************************************************************************/



#endif /* TRANSLATIONS_H */

