#ifndef OBJECT_HEADER
#define OBJECT_HEADER

#include "Vector3.hpp"

class Object
{
protected:
    Vector3 position;

public:
    Object(const Vector3 arg) : position(arg) {}

    virtual double dist_from_point(const Vector3 point);

    Vector3 get_position() { return position; }
    void set_position(const Vector3 arg) { position = arg; }
};

#endif
