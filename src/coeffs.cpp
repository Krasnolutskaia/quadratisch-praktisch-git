#include <stdio.h>
#include "utilities.h"
#include "solvers.h"
#include "color_print.h"


static double get_coeff()
{
    double coeff = 0;
    while (scanf("%lg", &coeff) != 1 || (getchar() != '\n'))
    {
        color_print(COLOR_RED, "invalid value\n"
                    "enter a new value");
        clear_buffer();
    }
    return coeff;
}


Coefficients get_coeffs()
{
    struct Coefficients coeffs = {
        0,
        0,
        0
    };
    color_print(COLOR_CYAN, "Enter coefficients a, b, c");
    color_print(COLOR_CYAN, "Enter coefficient a");
    coeffs.a = get_coeff();
    color_print(COLOR_CYAN, "Enter coefficient b");
    coeffs.b = get_coeff();
    color_print(COLOR_CYAN, "Enter coefficient c");
    coeffs.c = get_coeff();
    color_print(COLOR_CYAN, "Your coefficients: a = %lg, b = %lg, c = %lg", coeffs.a, coeffs.b, coeffs.c);
    return coeffs;
}


int print_roots(const EquationRoots roots)
{
    color_print(COLOR_CYAN, "*****************************************************");
    color_print(COLOR_GREEN, "Answer:");
    switch(roots.n_roots)
    {
    case NO_ROOTS:
            color_print(COLOR_GREEN, "No roots");
        break;

    case ONE_ROOT:
            color_print(COLOR_BLUE, "x = %lg", roots.x1);
        break;

    case TWO_ROOTS:
            color_print(COLOR_MAGENTA, "x1 = %lg, x2 = %lg", roots.x1, roots.x2);
        break;

    case INF_ROOTS:
            color_print(COLOR_CYAN, "Any number");
        break;

    default:
            color_print(COLOR_RED, "main(): ERROR: nRoots = %d", roots.n_roots);
        return 0;
    }
    return 1;
}
