//==============================================================================================
//! @file   tests.h
//==============================================================================================
#ifndef TESTS_H_
#define TESTS_H_

#include "common.h"


//{-------------------------------------------------------------------------------------
//! Run tests with data from file
//!
//! @param  file    pointer to file with data
//! 
//! @note   Prints number of successful tests;
//!         if test didn't succed, print number of that test and information about it
//}-------------------------------------------------------------------------------------
void run_tests_from_file(FILE* file);


//{-------------------------------------------------------------------------------------
//! Run built-in tests
//!
//! @note   Prints number of successful tests;
//!         if test didn't succed, print number of that test and information about it
//}-------------------------------------------------------------------------------------
void run_auto_test();

#endif
