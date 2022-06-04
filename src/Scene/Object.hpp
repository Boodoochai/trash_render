#ifndef OBJECT_HEADER
#define OBJECT_HEADER

#include "Vector3.hpp"
#include "Quaternion.hpp"
#include "DistanceEstimator.hpp"

class CompositeObject;
class Scene;

class Object
{
private:
    long id;

protected:
    CompositeObject *parent;

    Object() = default;
    Object(const long arg1, CompositeObject *arg2) 
        : id(arg1) , parent(arg2) {}
    
public:
    virtual ~Object() = default;

    long get_id() { return id; }

    virtual Object *copy_to(const long id, 
                            Scene *scene, 
                            CompositeObject *parent) const = 0;
    virtual void rotate(const Quaternion quaternion) = 0;
    virtual void rotate_around(const Vector3 point,
                               const Quaternion quaternion) = 0;
    virtual void translate(const Vector3 arg) = 0;
    virtual DistanceEstimator *get_distance_estimator() const = 0;

    virtual Vector3 get_relative_position() const = 0;
    virtual Vector3 get_rotation() const = 0;
    virtual Vector3 get_absolute_position() const = 0;
    virtual void set_rotation(const Vector3 rotation) = 0;
    virtual void set_relative_position(const Vector3 relative_position) = 0;
    virtual void update_position() = 0;
};

#endif
