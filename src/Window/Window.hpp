#ifndef WINDOW_HEADER
#define WINDOW_HEADER

#include "Vector2.hpp"

struct Window {
  Vector2 position;
  Vector2 size;

  Window(Vector2 position, Vector2 size) : position(position), size(size) {}
};

#endif
