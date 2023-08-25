#include "tests.h"


static bool is_equal(const double a, const double b)
{
    if (fabs(a - b) < EPS)
    {
        return true;
    }
    return false;
}


static void close_file(FILE* file)
{
    if (fclose(file) != 0)
    {
        printf("Can't close file");
    }
}


static void clear_buffer_file(FILE* file)
{
    int ch = getc(file);
    while (ch != '\n' && ch != EOF)
    {
        ch = getc(file);
    }
}


static int test_one(const TestData* data)
{
    const EquationRoots roots = solve_square(data->coeffs);
    const double x1 = roots.x1, x2 = roots.x2;
    const int n_roots = roots.n_roots;

    if (!is_equal(x1, data->roots.x1) || !is_equal(x2, data->roots.x2) || n_roots != data->roots.n_roots)
    {
        printf("FAILED: TEST #%d\n", data->n_test);
        printf("x1 = %lg, x1_ref = %lg;\nx2 = %lg, x2_ref = %lg;\nn_root = %d, n_root_ref = %d;\n",
                x1, data->roots.x1, x2, data->roots.x2, n_roots, data->roots.n_roots);
        printf("a = %lg b = %lg c = %lg\n", data->coeffs.a, data->coeffs.b, data->coeffs.c);
        return 0;
    }
    return 1;
}


void tests_from_file(FILE* file)
{
    int n_tests = 0;
    if (fscanf(file, "%d", &n_tests) != 1)
    {
        printf("ERROR: Can't read number of tests\n");
        exit(EXIT_FAILURE);
    }

    if (n_tests > 0)
    {
        TestData data =
        {
            {0, 0, 0},
            {0, 0, NO_ROOTS},
            0,
        };
        int succeeded_tests = 0;

        for (int i = 0; i < n_tests; i++)
        {
            if (fscanf(file, "%lg %lg %lg %lg %lg %d", &data.coeffs.a, &data.coeffs.b, &data.coeffs.c,
                    &data.roots.x1, &data.roots.x2, &data.roots.n_roots) != 6)
            {
                printf("ERROR: Can't read test #%d\n", i + 1);
                clear_buffer_file(file);
            }
            else
            {
                data.n_test = i + 1;
                succeeded_tests += test_one(&data);
            }
        }

        printf("Succeeded test: %d out of %d\n", succeeded_tests, n_tests);
    }
    else
    {
        printf("ERROR: Number of tests is zero or less\n");
    }

    close_file(file);
}


int test_all()
{
    int succeeded_tests = 0;

    TestData all_data[N_TESTS] = {
        {{0, 0, 0},  {0, 0, INF_ROOTS},  1},
        {{0, 0, 4},  {0, 0, NO_ROOTS},   2},
        {{0, 2, -2}, {1, 1, ONE_ROOT},   3},
        {{1, 2, 2},  {0, 0, NO_ROOTS},   4},
        {{1, 2, 1},  {-1, -1, ONE_ROOT}, 5},
        {{1, -3, 2}, {1, 2, TWO_ROOTS},  6},
        {{1, 0, -4}, {-2, 2, TWO_ROOTS}, 7},

    };

    for (int i = 0; i < N_TESTS; i++)
    {
        succeeded_tests += test_one(&all_data[i]);
    }

    return succeeded_tests;
}
