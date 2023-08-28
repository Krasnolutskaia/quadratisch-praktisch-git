#ifndef COEFFS_H_
#define COEFFS_H_

#include "common.h"


//{-------------------------------------------
//! Get 3 coefficients from stdin
//! 
//! @see    get_coeff()
//!
//! @note   Returns struct Coefficients with received coefficients from stdin
//}-------------------------------------------
Coefficients get_coeffs();

//{-------------------------------------------
//! Prints nummber of roots
//! 
//! @param  roots   struct of equation roots
//}-------------------------------------------
int print_roots(const EquationRoots roots);


#endif