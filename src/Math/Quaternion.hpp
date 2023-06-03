#ifndef QUATERNION_HEADER
#define QUATERNION_HEADER

#include "Vector3.hpp"

class Quaternion {
public:
  double re;
  Vector3 im;

  Quaternion(const double arg1, Vector3 arg2) : re(arg1), im(arg2) {}
  Quaternion(const double arg1) : re(arg1), im(Vector3(0, 0, 0)) {}
  Quaternion(const Vector3 arg1) : re(0), im(arg1) {}
  Quaternion(double arg1, double arg2, double arg3, double arg4)
      : re(arg1), im(Vector3(arg2, arg3, arg4)) {}

  double absolute() const;
  Quaternion conjugated() const;
  Quaternion normalized() const;
  Quaternion inverse() const;
  double dot_product(const Quaternion arg) const;
  Vector3 rotate_vector(const Vector3 vec) const;

  Quaternion operator+(const Quaternion arg) const;
  Quaternion &operator+=(const Quaternion arg);
  Quaternion operator-(const Quaternion arg) const;
  Quaternion &operator-=(const Quaternion arg);
  Quaternion operator*(const Quaternion arg) const;
  Quaternion &operator*=(const Quaternion arg);
  Quaternion operator/(const double arg) const;
  Quaternion &operator/=(const double arg);
  Quaternion operator*(const double arg) const;
  Quaternion &operator*=(const double arg);
};

Quaternion operator*(const double arg1, const Quaternion arg2);

#endif
