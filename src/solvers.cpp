#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "solvers.h"
#include "utilities.h"


static EquationRoots solve_linear(const double a, const double b)
{
    assert(isfinite(a));
    assert(isfinite(b));

    EquationRoots roots = {
        0,
        0,
        NO_ROOTS
    };

    if (is_zero(a))
    {
        if (is_zero(b))
        {
            roots.n_roots = INF_ROOTS;
            return roots;
        }
        roots.n_roots = NO_ROOTS;
        return roots;
    }
    else
    {
        roots.x1 = roots.x2 = -b / a;
        roots.n_roots = ONE_ROOT;
    }
    return roots;
}


EquationRoots solve_square(const Coefficients coeffs)
{
    const double a = coeffs.a;
    const double b = coeffs.b;
    const double c = coeffs.c;

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    EquationRoots roots = {
        0,
        0,
        NO_ROOTS
    };

    if (is_zero(a))
    {
        return solve_linear(b, c);
    }
    else
    {
        double d = b*b - 4*a*c;

        if (is_zero(d))
        {
            
            roots.x1 = roots.x2 = -b / (2*a);
            roots.n_roots = ONE_ROOT;
        }
        else if (compare_with_zero(d) == -1)
        {
            roots.n_roots = NO_ROOTS;
        }
        else
        {
            double sqrt_d = sqrt(d);
            roots.x1 = (-b - sqrt_d) / (2*a);
            roots.x2 = (-b + sqrt_d) / (2*a);
            roots.n_roots = TWO_ROOTS;
        }
    }
    return roots;
}
