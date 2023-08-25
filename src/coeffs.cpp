#include <stdio.h>
#include "utilities.h"
#include "solvers.h"


#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"


static double get_coeff()
{
    double coeff = 0;
    while (scanf("%lg", &coeff) != 1 || (getchar() != '\n'))
    {
        printf(COLOR_RED "invalid value\n"
               "enter a new value" COLOR_RESET "\n");
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
    printf(COLOR_CYAN "Enter coefficients a, b, c\n");
    printf("Enter coefficient a" COLOR_RESET "\n");
    coeffs.a = get_coeff();
    printf(COLOR_CYAN "Enter coefficient b" COLOR_RESET "\n");
    coeffs.b = get_coeff();
    printf(COLOR_CYAN "Enter coefficient c" COLOR_RESET "\n");
    coeffs.c = get_coeff();
    printf(COLOR_CYAN "Your coefficients: a = %lg, b = %lg, c = %lg" COLOR_RESET "\n", coeffs.a, coeffs.b, coeffs.c);
    return coeffs;
}


int print_roots(const EquationRoots roots)
{
    printf(COLOR_CYAN "*****************************************************" COLOR_RESET "\n");
    printf(COLOR_GREEN "Answer: " COLOR_RESET);
    switch(roots.n_roots)
    {
    case NO_ROOTS:
            printf(COLOR_GREEN "No roots" COLOR_RESET "\n");
        break;

    case ONE_ROOT:
            printf(COLOR_BLUE "x = %lg" COLOR_RESET "\n", roots.x1);
        break;

    case TWO_ROOTS:
            printf(COLOR_MAGENTA "x1 = %lg, x2 = %lg" COLOR_RESET "\n", roots.x1, roots.x2);
        break;

    case INF_ROOTS:
            printf(COLOR_CYAN "Any number" COLOR_RESET "\n");
        break;

    default:
            printf(COLOR_RED "main(): ERROR: nRoots = %d" COLOR_RESET "\n", roots.n_roots);
        return 0;
    }
    return 1;
}
