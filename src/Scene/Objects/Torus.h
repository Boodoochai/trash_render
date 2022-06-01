#ifndef TORUS_HEADER
#define TORUS_HEADER

#include "Object.h"

class Torus : public Object
{
private:
    double R;
    double r;
    Vector3 norm;

public:
    Torus(const Vector3 arg1, double arg2, double arg3, Vector3 arg4)
        : Object(arg1)
        , R(arg2)
        , r(arg3) 
        , norm(arg4) {}
    
    double dist_from_point(const Vector3 point);
};

#endif
