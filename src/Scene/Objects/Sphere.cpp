#include "Sphere.h"

double Sphere::dist_from_point(const Vector3 point)
{
    double x = point.x - position.x;
    double y = point.y - position.y;
    double z = point.z - position.z;
    return sqrt(x*x + y*y + z*z) - radius;
}
