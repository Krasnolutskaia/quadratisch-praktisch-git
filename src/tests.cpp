#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "tests.h"
#include "solvers.h"
#include "utilities.h"
#include "color_print.h"


struct TestData {
    Coefficients coeffs;
    EquationRoots roots;
};


static void close_file(FILE* file)
{
    if (fclose(file) != 0)
    {
        color_print(COLOR_RED, "Can't close file");
        exit(EXIT_FAILURE);
    }
}


static void clear_buffer_file(FILE* file)
{
    int ch = 0;
    do {
        ch = getc(file);
    }
    while (ch != '\n' && ch != EOF);
}


static bool are_tests_different(EquationRoots roots, const TestData* data)
{
    const double x1 = roots.x1, x2 = roots.x2;
    const int n_roots = roots.n_roots;
    return !is_equal(x1, data->roots.x1) || !is_equal(x2, data->roots.x2) || n_roots != data->roots.n_roots;
}


static int run_one_test(const TestData* data, const int n_test)
{
    const EquationRoots roots = solve_square(data->coeffs);
    const double x1 = roots.x1, x2 = roots.x2;
    const int n_roots = roots.n_roots;

    if (are_tests_different(roots, data))
    {
        color_print(COLOR_RED, "FAILED: TEST #%d", n_test);
        color_print(COLOR_RED, "x1 = %lg, x1_ref = %lg;\nx2 = %lg, x2_ref = %lg;\nn_root = %d, n_root_ref = %d;",
                x1, data->roots.x1, x2, data->roots.x2, n_roots, data->roots.n_roots);
        color_print(COLOR_RED, "a = %lg b = %lg c = %lg", data->coeffs.a, data->coeffs.b, data->coeffs.c);
        return 0;
    }
    return 1;
}


static bool check_test_data(FILE* file, TestData* data)
{
    return fscanf(file, "%lg %lg %lg %lg %lg %d", &data->coeffs.a, &data->coeffs.b, &data->coeffs.c,
                  &data->roots.x1, &data->roots.x2, &data->roots.n_roots) != 6;
}


static int scan_tests_num(FILE* file)
{
    int tests_num = 0;
    if (fscanf(file, "%d", &tests_num) != 1)
    {
        color_print(COLOR_RED, "ERROR: Can't read number of tests");
        close_file(file);
        exit(EXIT_FAILURE);
    }
    return tests_num;
}


void run_tests_from_file(FILE* file)
{
    assert(file != nullptr);
    int tests_num = scan_tests_num(file);

    if (tests_num > 0)
    {
        TestData data =
        {
            {0, 0, 0},
            {0, 0, NO_ROOTS}, // nan
        };
        int succeeded_tests = 0;

        for (int i = 1; i <= tests_num; i++)
        {
            if (check_test_data(file, &data))
            {
                color_print(COLOR_RED,  "ERROR: Can't read test #%d", i);
                clear_buffer_file(file);
            }
            else
            {
                succeeded_tests += run_one_test(&data, i);
            }
        }

        color_print(COLOR_GREEN, "Succeeded test: %d out of %d", succeeded_tests, tests_num);
    }
    else
    {
        color_print(COLOR_RED, "ERROR: Number of tests is zero or less");
    }

    close_file(file);
}


void run_auto_test()
{
    int succeeded_tests = 0;

    TestData all_data[] = {
        {{0, 0, 0},  {0, 0, INF_ROOTS}},
        {{0, 0, 4},  {0, 0, NO_ROOTS}},
        {{0, 2, -2}, {1, 1, ONE_ROOT}},
        {{1, 2, 2},  {0, 0, NO_ROOTS}},
        {{1, 2, 1},  {-1, -1, ONE_ROOT}},
        {{1, -3, 2}, {1, 2, TWO_ROOTS}},
        {{1, 0, -4}, {-2, 2, TWO_ROOTS}},
    };

    int tests_num = sizeof(all_data) / sizeof(TestData);

    for (int i = 0; i < tests_num; i++)
    {
        succeeded_tests += run_one_test(&all_data[i], i + 1);
    }

    color_print(COLOR_GREEN, "Succeed %d tests out of %d", succeeded_tests, tests_num);
}
