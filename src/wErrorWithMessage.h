/*----------------------------------------------------------------------------------------------------------------------------------
//
//                                                        _____                     
//                                              __      _| ____|_ __ _ __ ___  _ __ 
//                                              \ \ /\ / /  _| | '__| '__/ _ \| '__|
//                                               \ V  V /| |___| |  | | | (_) | |   
//                                                \_/\_/ |_____|_|  |_|  \___/|_|   
//
//
//
// File: 	wErrorWithMessage.h
//	
// Lang.:	C
//	
// Abstr.:	Simple class dedicated to the exception managing where an ASCII message has been included in the exception's data
//
// Authour:	Silvano Catinella <catinella@yahoo.com>
//
// Description:
//		You can use this objects type everytime your function need to pass an exception-message to the caller. Eg. when
//		you are using a logger the log-header is defined in the main, as usual.
//
// License:  LGPL ver 3.0
//
// 		This script is a wfree software; you can redistribute it and/or modify it under the terms	of the GNU
// 		Lesser General Public License as published by the Free Software Foundation; either version 3.0 of the License,
// 		or (at your option) any later version. 
//
//		For further details please read the full LGPL text file  "Linuxwoodo/trunk/templates/lgpl-3.0.txt".
// 		You should have received a copy of the GNU General Public License along with this file; 
// 		if not, write to the 
//
//			Free Software Foundation, Inc.,
//			59 Temple Place, Suite 330,
//			Boston, MA  02111-1307  USA
//
//
//
// [!] In order to obtain a clear look of this script, set the following parameters in your editor: cols=132 tab-size=6
----------------------------------------------------------------------------------------------------------------------------------*/
#pragma once

#include <stdarg.h>

#define WERROR_WITHMESSAGE  8
#define WERROR_MESSAGE_SIZE 255

typedef struct _we wError_t;

typedef struct {
	char message[WERROR_MESSAGE_SIZE];
} wErrorWithMessage_t;


void wErrorWithMessage_init (wError_t *obj);
void wErrorWithMessage_set  (wError_t *obj, const char *format, ...);


// WERROR_SUBCLASS_ID::          WERROR_WITHMESSAGE
// WERROR_SUBCLASS_EXTRAFIELD::  wErrorWithMessage_t withMessage
// WERROR_SUBCLASS_INITPROC::    wErrorWithMessage_init
