#ifndef UTILITIES_H_
#define UTILITIES_H_

//{---------------------------------------------------
//! Checks if two numbers are equal  
//!
//! @param  a   1st number
//! @param  b   2nd number
//!
//! @note   Returns true, if numbers are equal;
//!         returns false, if not.
//!
//! @par Usage example
//! @code
//!         bool check = is_equal(a, b);
//! @endcode
//}---------------------------------------------------
bool is_equal(double a, double b);


//{---------------------------------------------------
//! Checks if a number is zero, bigger than zero, less than zero 
//!
//! @param  n   number for checking
//!
//! @note   Returns 0, if a number is zero;
//!         returns -1, if a number is less than zero;
//!         returns 1, if a number is bigger than zero.
//!
//! @par Usage example
//! @code 
//!         int check = compare_with_zero(n);
//! @endcode
//}---------------------------------------------------
int compare_with_zero(double n);


//{---------------------------------------------------
//! Checks if a number is equal to zero 
//!
//! @param  n   number for checking
//!
//! @note   Returns 0, if a number is zero;
//!         returns -1, if a number is less than zero;
//!         returns 1, if a number is bigger than zero.
//!
//! @par Usage example
//! @code 
//!         bool check = is_zero(n);
//! @endcode
//}---------------------------------------------------
bool is_zero(double n);


//{---------------------------------------------------
//! Clears buffer
//}---------------------------------------------------
void clear_buffer();


#endif
