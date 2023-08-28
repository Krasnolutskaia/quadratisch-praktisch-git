//==============================================================================================
//! @file   common.h
//==============================================================================================
#ifndef COMMON_H_
#define COMMON_H_


const char TEST_MODE[] = "--test";
const char AUTO_TEST_MODE[] = "--auto-test";
const char HELP_MODE[] = "--help";

struct Coefficients {
    double a;
    double b;
    double c;
};

struct EquationRoots {
    double x1;
    double x2;
    int n_roots;
};

enum NumOfRoots {
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS,
    INF_ROOTS,
};


#endif