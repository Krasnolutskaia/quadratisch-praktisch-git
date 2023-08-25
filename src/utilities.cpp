#include <math.h>
#include <stdio.h>
#include "utilities.h"


const double EPS = 1e-6;


bool is_equal(double a, double b)
{
    return fabs(a - b) < EPS;
}


bool is_zero(double n)
{
    return fabs(n) < EPS;
}


int compare_with_zero(double n)
{
    if (fabs(n) < EPS) // is equal to zero
    {
        return 0;
    }
    if (n < -EPS) // is less than zero
    {
        return -1;
    }
    return 1; // is bigger than zero
}


void clear_buffer()
{
    while (getchar() != '\n')
        ;
}
