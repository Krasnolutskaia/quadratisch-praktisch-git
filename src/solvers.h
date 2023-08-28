//==============================================================================================
//! @file   solvers.h
//==============================================================================================
#ifndef SOLVERS_H_
#define SOLVERS_H_

#include "common.h"


//{------------------------------------------------------
//! Solves square equation
//!
//! @param  coeffs  struct of coeffs(a, b and c)
//!
//! @note   Returns struct of equation roots
//!
//! @see    solve_linear()
//}
EquationRoots solve_square(const Coefficients coeffs);

#endif
