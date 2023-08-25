#include "comparison_with_zero.h"

bool is_zero(double n)
{
    if (fabs(n) < EPS_ZERO)
    {
        return true;
    }
    return false;
}


bool less_zero(double n)
{
    if (n < -EPS_ZERO)
    {
        return true;
    }
    return false;
}
