/* 
 * Copyright (c) 2004 Apple Computer, Inc. All Rights Reserved.
 * 
 * @APPLE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */

/*
 *  ccdebug.h - CommonCrypto debug macros
 *  MacTomCrypt
 *
 */
#ifndef APPORTABLE
#include <asl.h>
#endif
#include <stdarg.h>

#define CC_DEBUG_FAILURE		ASL_LEVEL_EMERG
#define CC_DEBUG_BUG			ASL_LEVEL_ERR
#define CC_DEBUG					ASL_LEVEL_DEBUG

#ifdef APPORTABLE
#define ccdebug(lvl,fmt,...) {}
#else
void ccdebug_imp(int level, char *funcname, char *format, ...);
#define ccdebug(lvl,fmt,...) ccdebug_imp(lvl, __PRETTY_FUNCTION__, fmt, __VA_ARGS__)
#endif

