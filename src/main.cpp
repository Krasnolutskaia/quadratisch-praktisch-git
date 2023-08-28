//{------------------------------------------------------------------------------------------------
//! Solves a square equation ax^2 + bx + x = 0
//!
//! @return Number of roots
//!
//! @note   In case of infinite number of roots,
//!         returns INF_ROOTS
//}------------------------------------------------------------------------------------------------

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "solvers.h"
#include "tests.h"
#include "utilities.h"
#include "coeffs.h"
#include "common.h"
#include "color_print.h"


//{------------------------------------------------------------------------------------------------
//! Prints help text
//}------------------------------------------------------------------------------------------------
static void print_help(char file_name[]);


//{------------------------------------------------------------------------------------------------
//! Prints offer for help
//}------------------------------------------------------------------------------------------------
static void print_offer_help(char file_name[]);


static void parse_args(int argc, char* argv[]);


int main(int argc, char *argv[])
{
    parse_args(argc, argv);

    return 0;
}


static void print_help(char file_name[])
{
    color_print(COLOR_CYAN, "This program solves quadratic equations");
    color_print(COLOR_CYAN, "To enter auto test-mode run \"%s --auto-test\"", file_name);
    color_print(COLOR_CYAN, "To enter test-mode with data from file run \"%s --test file_name\"", file_name);
    color_print(COLOR_CYAN, "EXAMPLE:");
    color_print(COLOR_CYAN, "input_file_name");
    color_print(COLOR_CYAN, "---------------");
    color_print(COLOR_CYAN, "2");
    color_print(COLOR_CYAN, "0 0 0 0 0 3");
    color_print(COLOR_CYAN, "1 -3 2 1 2 2");
}


static void print_offer_help(char file_name[])
{
    color_print(COLOR_YELLOW, "Run \"%s help\" for help", file_name);
}


static void parse_args(int argc, char* argv[])
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
                    color_print(COLOR_RED, "Can't open %s", argv[i + 1]);
                    print_offer_help(argv[0]);
                    i += 2;
                    continue;
                }
                run_tests_from_file(file);
                i += 2;
            }
            else
            {
                color_print(COLOR_RED, "To enter test-mode file name is required");
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
            color_print(COLOR_RED, "\"%s\" arg if not found", argv[i]);
            print_offer_help(argv[0]);
            i++;
        }
    }
}
//переделать help