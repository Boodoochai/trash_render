#ifndef RAY_HEADER
#define RAY_HEADER

#include "Vector3.h"

class Ray
{
private:
    Vector3 position;
    Vector3 direction;

public:
    Ray(Vector3 arg1, Vector3 arg2)
        : position(arg1)
        , direction(arg2.normalized()) {}

    static Ray ray_from_points(Vector3 from, Vector3 to) 
        { return Ray(from, Vector3(to - from).normalized()); }

    Vector3 get_position() { return position; }
    Vector3 get_direction() { return direction; }
    void set_position(Vector3 arg) { position = arg; }
    void set_direction(Vector3 arg) { direction = arg.normalized(); }
};

#endif
