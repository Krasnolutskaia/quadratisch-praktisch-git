//==============================================================================================
//! @file   color_print.h
//==============================================================================================
#ifndef COLOR_PRINT_H_
#define COLOR_PRINT_H_

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"


//{--------------------------------------------------------------
//! Print colorful text
//!
//! @param  COLOR   desired text color
//! @param  format  a list of arguments whose number can vary
//!
//! @note Automatically adds "\n" to the end
//}--------------------------------------------------------------
void color_print(const char COLOR[], const char* format, ...);

#endif
