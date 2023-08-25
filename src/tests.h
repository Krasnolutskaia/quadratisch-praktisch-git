#ifndef TESTS_H_
#define TESTS_H_

#include "solver_function.h"


struct TestData {
    Coefficients coeffs;
    EquationRoots roots;
    int n_test;
};

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

const int N_TESTS = 7;
const double EPS = 1e-6;

const char TEST_MODE[] = "--test";
const char AUTO_TEST_MODE[] = "--auto-test";
const char HELP_MODE[] = "--help";


void tests_from_file(FILE* file);

int test_all();

#endif

