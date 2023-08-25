//------------------------------------------------
//! Solves a square equation ax^2 + bx + x = 0
//!
//! @return Number of roots
//!
//! @note   In case of infinite number of roots,
//!         returns INF_ROOTS
//------------------------------------------------


#include <string.h>
#include <stdlib.h>
#include "solver_function.h"
#include "tests.h"


void clear_buffer()
{
    while (getchar() != '\n')
        ;
}


double get_coeff()
{
    double coeff = 0;
    while (scanf("%lg", &coeff) != 1 || (getchar() != '\n'))
    {
        printf(COLOR_RED "invalid value\n");
        printf("enter a new value" COLOR_RESET "\n");
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
    printf(COLOR_CYAN "Enter coefficients a, b, c" COLOR_RESET "\n");
    printf(COLOR_CYAN "Enter coefficient a" COLOR_RESET "\n");
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


void choose_mode(const int argc, char* argv[])
{   
    if (argc == 1)
    {
        struct Coefficients coeffs = get_coeffs();
        EquationRoots roots = solve_square(coeffs);
        print_roots(roots);
    }

    int i = 1;
    while (i < argc)
    {
        if (strcmp(argv[i], HELP_MODE) == 0)
        {
            printf(COLOR_CYAN "This program solves quadratic equations\n");
            printf("To enter auto test-mode try \"%s test\"\n", argv[0]);
            printf("To enter test-mode with data from file try \"%s test file_name\"\n", argv[0]);
            printf("EXAMPLE:\n");
            printf("input_file_name\n");
            printf("---------------\n");
            printf("2\n");
            printf("0 0 0 0 0 3\n");
            printf("1 -3 2 1 2 2" COLOR_RESET "\n");
            i++;
        }
        else if (strcmp(argv[i], TEST_MODE) == 0)
        {
            if (i + 1 < argc)
            {
                FILE *file = NULL;
                if ((file = fopen(argv[i + 1], "r")) == NULL)
                {
                    printf(COLOR_RED "Can't open %s" COLOR_RESET "\n", argv[i + 1]);
                    printf(COLOR_YELLOW "Try \"%s help\" for help" COLOR_RESET "\n", argv[0]);
                    i += 2;
                    continue;
                }
                tests_from_file(file);
                i += 2;
            }
            else
            {
                printf(COLOR_RED "To enter test-mode file name is required" COLOR_RESET "\n");
                printf(COLOR_YELLOW "Try \"%s help\" for help" COLOR_RESET "\n", argv[0]);
                i++;
            }
        }
        else if (strcmp(argv[i], AUTO_TEST_MODE) == 0)
        {
            printf(COLOR_GREEN "Succeed %d tests out of %d" COLOR_RESET "\n", test_all(), N_TESTS);
            i++;
        }
        else
        {
            printf(COLOR_RED "\"%s\" arg if not found" COLOR_RESET "\n", argv[i]);
            printf(COLOR_YELLOW "Try \"%s help\" for help" COLOR_RESET "\n", argv[0]);
            i++;
        }
    }
}


int main(int argc, char *argv[])
{
    choose_mode(argc, argv);

    return 0;
}
