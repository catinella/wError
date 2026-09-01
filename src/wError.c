/*----------------------------------------------------------------------------------------------------------------------------------
//
//
//                                                        _____                     
//                                              __      _| ____|_ __ _ __ ___  _ __ 
//                                              \ \ /\ / /  _| | '__| '__/ _ \| '__|
//                                               \ V  V /| |___| |  | | | (_) | |   
//                                                \_/\_/ |_____|_|  |_|  \___/|_|   
//                                                   
//
//
// File: 	wError.c
//	
// Lang.:	C
//	
// Abstr.:	Simple class dedicated to the exception managing
//
// Authour:	Silvano Catinella <catinella@yahoo.com>
//
// Description:
//		This module provides you a set of structures you can use to manage your exceptions. In fact they can solve a common
//		C-programming problem about function's exit-codes: the missing information on the exception.
//		In C++, for example, you can always throw an object as exception, and you can fill the object with all needed
//		information. It allows you to manage the exception in better ways.
//		This module allows you to achieve a similar result: it your function returns a wError_t object then you will be able
//		to store in the object all info about the exception (also call-backs) according to the wErrorWith<label> sub modules.
//		
//		How it functions:
//			wError_t is composet by a stardard beginning part, used to evaluate the executed procedure status (success,
//			warning, failure), an exit-code data type, and a specific field for that type.
//			In order to store all possible information data type, wError uses a union structure. The final wError_t
//			definition is built dinamically parsing all sub-modules header files.
//		
//		How to write new sub-modules:
//			The main idea under the wError software is to leave the user free to write his own error handlers based on his
//			software requirements and necessities.
//			Every sub-module file name must respect the wErrorWith<label>.h syntax, and it must have the following
//			settings as comments:
//				- WERROR_SUBCLASS_ID::
//				  The numeric code used to define the new exception data type
//				- WERROR_SUBCLASS_EXTRAFIELD::
//				  The wError_t union's field definition
//				- WERROR_SUBCLASS_INITPROC::
//				  The new data-type initialization procedure
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
#include <stdbool.h>

bool wError_init (wError_t *obj, wError_exception_t extype) {
	//
	// Description
	//	It initializes the structure fields.
	//	
	// Returned vale:
	//	true   The object has been initialized
	//	false  The required exception type does not exists
	//
	bool err = true;

	obj->exceptionType = extype;
	obj->errorCode     = 0;

	switch (obj->exceptionType) {
		case WERROR_JUSTCODE:
			// Nothing to do
		break;

#include "initCSectFile.x"

		default:
			// ERROR!
			err = false;
		break;
	}
	return(err);
};

int wError_shellCode (wError_t obj) {
	//
	// Description:
	//	It converts the argument defined wError code in a Unix Shell exit-code.
	//
	int out = 0;

	if      (WERROR_GETCODE(obj) == 0)     out = 1;
	else if (WERROR_ISERROR(obj) == false) out = 0;
	else                                   out = WERROR_GETCODE(obj);

	return(out);
}

