/*
 * Copyright (c) 2015 - 2018 Filip "widelec" Maryjanski, BlaBla group.
 * All rights reserved.
 * Distributed under the terms of the GNU Lesser General Public License v2.1.
 */

#ifndef __IKSHOOKS_H__
#define __IKSHOOKS_H__

int StreamHook(void *user_data, int type, iks *node);

#ifdef __DEBUG__
void DebugHook(void *user_data, const char *data, size_t size, int is_incoming);
#endif /* __DEBUG__ */

#endif /* __IKSHOOKS_H__ */
