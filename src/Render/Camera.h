#ifndef CAMERA_HEADER
#define CAMERA_HEADER

#include "Vector3.h"
#include "Vector2.h"
#include "Ray.h"

class Camera
{
public:
    Vector3 position;
    Vector3 screen_position;
    Vector2 screen_size;

    Camera(const Vector3 arg1, const Vector3 arg2, const Vector2 arg3)
        : position(arg1)
        , screen_position(arg2)
        , screen_size(arg3) {}
};

#endif