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
// File: 	wErrorWithMessage_test.c
//	
// Lang.:	C
//	
// Abstr.:	Simple class dedicated to the exception managing
//
// Authour:	Silvano Catinella <catinella@yahoo.com>
//
// Description:
//	It is a simple test to show how to use wErrorWithMessage class
//
// [!] In order to obtain a clear look of this script, set the following parameters in your editor: cols=132 tab-size=6
----------------------------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <wError.h>
#include <wError_test.h>

wError_t function_a() {
	wError_t err;

	if (wError_init(&err, WERROR_WITHMESSAGE)) {
		// ....function's tasks....

		// Error setting
		WERROR_GETCODE(err) = WERROR_ERROR_GENERIC;
		sprintf(err.withMessage.message, "%s(): Test message... bla bla bla...", __PRETTY_FUNCTION__);

	} else {
		// ERROR!
		printf("ERROR! Object initialization failed\n");
	}
	
	return(err);
}

int main() {
	wError_t myerr = function_a();

	if (WERROR_ISERROR(myerr)) {
		printf("Exception (code=%d) has been correctly detected\n", myerr.errorCode);
		if (WERROR_GETTYPE(myerr) == WERROR_WITHMESSAGE)
			printf("Error message: \"%s\"\n", myerr.withMessage.message);
		else
			printf("Test FAILED!\n");
	} else
		printf("Test FAILED (*) !\n");

	return(0);
}
