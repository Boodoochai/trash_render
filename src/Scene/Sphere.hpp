#ifndef SPHERE_HEADER
#define SPHERE_HEADER

#include <math.h>

#include "CompositeObject.hpp"
#include "Shape.hpp"
#include "SphereDistanceEstimator.hpp"
#include "Vector3.hpp"

class Sphere : public Shape {
private:
  Vector3 relative_position;
  Vector3 absolute_position;
  double radius;
  char color;

  Sphere(const long arg1, CompositeObject *arg2) : Shape(arg1, arg2) {}

public:
  virtual ~Sphere() = default;

  Sphere(const Vector3 pos, const double rad, const char col)
      : Shape(), relative_position(pos), radius(rad), color(col) {}

  char get_color() const override { return color; }
  void set_color(const char color) { this->color = color; }

  double get_radius() const { return radius; }
  void set_radius(const double radius) { this->radius = radius; }

  Object *copy_to(const long id, Scene *scene,
                  CompositeObject *parent) const override;

  void rotate(const Quaternion quaternion) override;
  void rotate_around(const Vector3 point, const Quaternion quaternion) override;
  void translate(const Vector3 arg) override;
  DistanceEstimator *get_distance_estimator() const override;

  Vector3 get_relative_position() const override { return relative_position; }
  Vector3 get_rotation() const override { return Vector3(); }
  Vector3 get_absolute_position() const override { return absolute_position; }
  void set_rotation(const Vector3 rotation) override {}
  void set_relative_position(const Vector3 relative_position) override;
  void update_position() override;
};

#endif
