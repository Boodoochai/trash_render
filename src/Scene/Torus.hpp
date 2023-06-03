#ifndef TORUS_HEADER
#define TORUS_HEADER

#include "Object.hpp"
#include "Shape.hpp"
#include "TorusDistanceEstimator.hpp"

class Torus : public Shape {
private:
  Vector3 relative_position;
  Vector3 absolute_position;
  double major_radius;
  double minor_radius;
  Vector3 rotation;
  char color;

  Torus(const long arg1, CompositeObject *arg2) : Shape(arg1, arg2) {}

public:
  virtual ~Torus() = default;

  Torus(const Vector3 pos, double R, double r, Vector3 rot, char col)
      : Shape(), major_radius(R), minor_radius(r), rotation(rot), color(col) {
    set_relative_position(pos);
  }

  char get_color() const { return color; }
  void set_color(const char color) { this->color = color; }
  double get_major_radius() const { return major_radius; }
  void set_major_radius(const double major_radius) {
    this->major_radius = major_radius;
  }
  double get_minor_radius() const { return minor_radius; }
  void set_minor_radius(const double minor_radius) {
    this->minor_radius = minor_radius;
  }

  Object *copy_to(const long id, Scene *scene,
                  CompositeObject *parent) const override;
  void rotate(const Quaternion quaternion) override;
  void rotate_around(const Vector3 point, const Quaternion quaternion) override;
  void translate(const Vector3 arg) override;
  DistanceEstimator *get_distance_estimator() const override;

  Vector3 get_relative_position() const override { return relative_position; }
  Vector3 get_rotation() const override { return rotation; }
  Vector3 get_absolute_position() const override { return absolute_position; }
  void set_rotation(const Vector3 rotation) override {
    this->rotation = rotation;
  }
  void set_relative_position(const Vector3 relative_position) override;
  void update_position() override;
};

#endif
