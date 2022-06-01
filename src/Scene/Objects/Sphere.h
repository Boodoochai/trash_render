#ifndef SPHERE_HEADER
#define SPHERE_HEADER

#include <math.h>

#include "Object.h"
#include "Vector3.h"

class Sphere : public Object
{
private:
    double radius;

public:
    Sphere(const Vector3 arg1, const double arg2) 
        : Object(arg1)
        , radius(arg2) {}

    virtual double dist_from_point(const Vector3 point);
};

#endif
