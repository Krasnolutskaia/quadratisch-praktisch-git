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
#include <stdio.h>
#include "solvers.h"
#include "tests.h"
#include "utilities.h"
#include "coeffs.h"


void print_help(char file_name[])
{
    printf(COLOR_CYAN "This program solves quadratic equations\n");
    printf("To enter auto test-mode try \"%s --auto-test\"\n", file_name);
    printf("To enter test-mode with data from file try \"%s --test file_name\"\n", file_name);
    printf("EXAMPLE:\n");
    printf("input_file_name\n");
    printf("---------------\n");
    printf("2\n");
    printf("0 0 0 0 0 3\n");
    printf("1 -3 2 1 2 2" COLOR_RESET "\n");
}


void print_offer_help(char file_name[])
{
    printf(COLOR_YELLOW "Try \"%s help\" for help" COLOR_RESET "\n", file_name);
}


void choose_mode(int argc, char* argv[])
{   
    if (argc == 1)
    {
        Coefficients coeffs = get_coeffs();
        EquationRoots roots = solve_square(coeffs);
        print_roots(roots);
    }

    int i = 1;
    while (i < argc)
    {
        if (strcmp(argv[i], HELP_MODE) == 0)
        {
            print_help(argv[0]);
            i++;
        }
        else if (strcmp(argv[i], TEST_MODE) == 0)
        {
            if (i + 1 < argc)
            {
                FILE *file = fopen(argv[i + 1], "r");
                if (file == nullptr)
                {
                    printf(COLOR_RED "Can't open %s" COLOR_RESET "\n", argv[i + 1]);
                    print_offer_help(argv[0]);
                    i += 2;
                    continue;
                }
                run_tests_from_file(file);
                i += 2;
            }
            else
            {
                printf(COLOR_RED "To enter test-mode file name is required" COLOR_RESET "\n");
                print_offer_help(argv[0]);
                i++;
            }
        }
        else if (strcmp(argv[i], AUTO_TEST_MODE) == 0)
        {
            run_auto_test();
            i++;
        }
        else
        {
            printf(COLOR_RED "\"%s\" arg if not found" COLOR_RESET "\n", argv[i]);
            print_offer_help(argv[0]);
            i++;
        }
    }
}


int main(int argc, char *argv[])
{
    choose_mode(argc, argv);

    return 0;
}
