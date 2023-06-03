#include "Torus.hpp"

Object *Torus::copy_to(const long id, Scene *scene,
                       CompositeObject *parent) const {
  Torus *new_torus = new Torus(id, parent);
  new_torus->relative_position = relative_position;
  new_torus->update_position();
  new_torus->major_radius = major_radius;
  new_torus->minor_radius = minor_radius;
  new_torus->rotation = rotation;
  new_torus->color = color;
  return new_torus;
}

void Torus::rotate(const Quaternion quaternion) {}

void Torus::rotate_around(const Vector3 point, const Quaternion quaternion) {
  Vector3 change =
      quaternion.rotate_vector(absolute_position) - absolute_position;
  absolute_position += change;
  relative_position += change;
  rotation = quaternion.rotate_vector(rotation);
}

void Torus::translate(const Vector3 position_change) {
  relative_position += position_change;
  absolute_position += position_change;
}

DistanceEstimator *Torus::get_distance_estimator() const {
  return new TorusDistanceEstimator(this);
}

void Torus::set_relative_position(const Vector3 relative_position) {
  Vector3 change = relative_position - this->relative_position;
  this->relative_position = relative_position;
  absolute_position += change;
}

void Torus::update_position() {
  absolute_position = parent->get_absolute_position() + relative_position;
}
