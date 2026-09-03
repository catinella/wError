/*----------------------------------------------------------------------------------------------------------------------------------
//
//                                                        _____                     
//                                              __      _| ____|_ __ _ __ ___  _ __ 
//                                              \ \ /\ / /  _| | '__| '__/ _ \| '__|
//                                               \ V  V /| |___| |  | | | (_) | |   
//                                                \_/\_/ |_____|_|  |_|  \___/|_|   
//
//
// File: 	wErrorWithMessage.c
//	
// Lang.:	C
//	
// Abstr.:	Simple class dedicated to the exception managing
//
// Authour:	Silvano Catinella <catinella@yahoo.com>
//
// Description:
//
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
#include <wError.h>
#include <wErrorWithMessage.h>
#include <stdio.h>
#include <string.h>

void wErrorWithMessage_init (wError_t *obj) {
	memset(obj->withMessage.message, '\0', WERROR_MESSAGE_SIZE * sizeof(char));
	return;
}

void wErrorWithMessage_set (wError_t *obj, const char *format, ...) {
	va_list args;
	int     ret = 0;

	va_start(args, format);
	ret = vsnprintf(obj->withMessage.message, WERROR_MESSAGE_SIZE, format, args);
	va_end(args);
	if (ret >= WERROR_MESSAGE_SIZE)
		strcpy((obj->withMessage.message + WERROR_MESSAGE_SIZE - 4), "...");

	return;
}
