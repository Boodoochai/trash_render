#ifndef VECTOR2_HEADER
#define VECTOR2_HEADER

#include <math.h>

class Vector2 {
public:
  double x;
  double y;

  explicit Vector2() : x(0), y(0) {}
  explicit Vector2(const double arg1, const double arg2) : x(arg1), y(arg2) {}

  Vector2 operator+(const Vector2 arg) const;

  Vector2 operator-(const Vector2 arg) const;

  Vector2 &operator+=(const Vector2 arg);

  Vector2 &operator-=(const Vector2 arg);

  Vector2 operator/(const double arg) const;

  Vector2 operator*(const double arg) const;

  Vector2 &operator/=(const double arg);

  Vector2 &operator*=(const double arg);

  double length();

  Vector2 normalized();
};

Vector2 operator*(const double arg1, const Vector2 arg2);

#endif
