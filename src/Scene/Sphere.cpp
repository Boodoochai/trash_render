#include "Sphere.hpp"

Object *Sphere::copy_to(const long id, Scene *scene, 
                        CompositeObject *parent) const
{
    Sphere *new_sphere = new Sphere(id, parent);
    new_sphere->relative_position = relative_position;
    new_sphere->update_position();
    new_sphere->radius = radius;
    new_sphere->color = color;
    return new_sphere;
}

void Sphere::rotate(const Quaternion quaternion)
{
       
}

void Sphere::rotate_around(const Vector3 point, const Quaternion quaternion)
{
    Vector3 change = quaternion.rotate_vector(absolute_position) - absolute_position;
    absolute_position += change;
    relative_position += change;
}

void Sphere::translate(const Vector3 arg)
{
    relative_position += arg;
    absolute_position += arg;
}

DistanceEstimator *Sphere::get_distance_estimator() const
{
    return new SphereDistanceEstimator(this);
}

void Sphere::set_relative_position(const Vector3 relative_position)
{
    Vector3 change = relative_position - this->relative_position;
    this->relative_position = relative_position;
    absolute_position += change;
}

void Sphere::update_position()
{
    absolute_position = parent->get_absolute_position() + relative_position;
}
