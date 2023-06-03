#ifndef CAMERA_HEADER
#define CAMERA_HEADER

#include "Ray.hpp"
#include "Vector2.hpp"
#include "Vector3.hpp"

class Camera {
public:
  Vector3 position;
  Vector3 screen_position;
  Vector2 screen_size;

  Camera(const Vector3 position, const Vector3 screen_position,
         const Vector2 screen_size)
      : position(position), screen_position(screen_position),
        screen_size(screen_size) {}
};

#endif
