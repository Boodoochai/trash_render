#include "Object.hpp"

double Object::dist_from_point(const Vector3 point)
{
    double x = point.x - point.x;
    double y = point.y - point.y;
    double z = point.z - point.z;
    return sqrt(x*x + y*y + z*z);
}
