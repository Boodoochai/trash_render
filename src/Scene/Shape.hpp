#ifndef SHAPE_HEADER
#define SHAPE_HEADER

#include "CompositeObject.hpp"
#include "Object.hpp"

class Shape : public Object {
protected:
  Shape() : Object(0, nullptr) {}
  Shape(const long arg1, CompositeObject *arg2) : Object(arg1, arg2) {}

public:
  virtual ~Shape() = default;

  virtual char get_color() const = 0;
  virtual void set_color(const char color) = 0;

  /*
      Object *copy_to(long id, Scene *scene) const override = 0;
      void rotate(const Quaternion quaternion) override = 0;
      void rotate_around(const Vector3 point,const Quaternion quaternion)
     override = 0; void translate(const Vector3 arg) override = 0; void
     destroy() override = 0; DistanceEstimator *get_distance_estimator() const
     override = 0;

      Vector3 get_relative_position() const override = 0;
      Vector3 get_rotation() const override = 0;
      Vector3 get_absolute_position() const override = 0;
      void set_rotation(const Vector3 rotation) override = 0;
      void set_relative_position(const Vector3 relative_position) override = 0;
      void set_absolute_position(const Vector3 absolute_position) override = 0;
  */
};

#endif
