#include "CompositeObject.hpp"

Object *CompositeObject::copy_to(const long id, Scene *scene, 
                                 CompositeObject *parent) const
{
    CompositeObject *new_composite = new CompositeObject(id, parent);
    new_composite->relative_position = relative_position;
    new_composite->update_position();
    for (auto &child : children){

    }
    return new_composite;
}

void CompositeObject::rotate(const Quaternion quaternion)
{
    for (auto &child : children){
        child->rotate_around(absolute_position, quaternion);
    }
}

void CompositeObject::rotate_around(const Vector3 point, const Quaternion quaternion)
{
    for (auto &child : children){
        child->rotate_around(point, quaternion);
    }
}

void CompositeObject::translate(const Vector3 arg)
{
    for (auto &child : children){
        child->translate(arg);
    }
}

DistanceEstimator *CompositeObject::get_distance_estimator() const
{
    return new CompositeDistanceEstimator(children);
}

void CompositeObject::set_relative_position(const Vector3 pos)
{
    Vector3 change = pos - relative_position;
    relative_position += change;
    absolute_position += change;
    for (auto &child : children){
        child->translate(change);
    }
}

void CompositeObject::update_position()
{
    absolute_position = parent->get_absolute_position() + relative_position;
}
