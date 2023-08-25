#ifndef TESTS_H_
#define TESTS_H_

#include "solver_function.h"


struct TestData {
    Coefficients coeffs;
    EquationRoots roots;
    int n_test;
};

const int N_TESTS = 7;
const double EPS = 1e-6;

const char TEST_MODE[] = "--test";
const char AUTO_TEST_MODE[] = "--auto-test";
const char HELP_MODE[] = "--help";


void tests_from_file(FILE* file);

int test_all();

#endif

