#ifndef SOLVERS_H_
#define SOLVERS_H_

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


EquationRoots solve_square(const Coefficients coeffs);

#endif
