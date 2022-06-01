#include "Torus.h"

double Torus::dist_from_point(const Vector3 point)
{
    Vector3 ao = position - point;
    Vector3 ah = ao.dot_product(norm) * norm;
    Vector3 ho = ao - ah;
    Vector3 ho1 = ho * (1 - R / ho.length());
    Vector3 ao1 = ah + ho1;
    Vector3 ax = ao1 * (1 - r / ao1.length());
    return ax.length();
}

