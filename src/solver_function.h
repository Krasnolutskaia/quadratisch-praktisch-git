#ifndef SOLVER_FUNCTION_H_
#define SOLVER_FUNCTION_H_

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "comparison_with_zero.h"


struct Coefficients {
    double a;
    double b;
    double c;
};

struct EquationRoots {
    double x1;
    double x2;
    int n_roots;
};

enum NumOfRoots {
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS,
    INF_ROOTS,
};

EquationRoots solve_linel(const double a, const double b);

EquationRoots solve_square(const Coefficients coeffs);


#endif
