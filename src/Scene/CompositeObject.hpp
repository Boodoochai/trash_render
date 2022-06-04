#ifndef COMPOSITE_OBJECT_HEADER
#define COMPOSITE_OBJECT_HEADER

#include "Object.hpp"
#include "Vector3.hpp"
#include "Quaternion.hpp"
#include "CompositeDistanceEstimator.hpp"

class CompositeObject : public Object
{
private:
    Vector3 relative_position;
    Vector3 absolute_position;

    CompositeObject(const long arg1, CompositeObject *arg2) : Object(arg1,arg2) {}

public:
    std::list<Object *> children;

public:
    virtual ~CompositeObject() = default;

    CompositeObject(const Vector3 pos) : Object(), relative_position(pos) {}

    Object *copy_to(const long id,
                    Scene *scene,
                    CompositeObject *parent) const override;
    void rotate(const Quaternion quaternion) override;
    void rotate_around(const Vector3 point,
                       const Quaternion quaternion) override;
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
