#ifndef SCENE_HEADER
#define SCENE_HEADER

#include <vector>

#include "Camera.hpp"
#include "Object.hpp"
#include "Ray.hpp"

class Scene {
private:
  Camera *camera;
  std::vector<Object *> objects;

public:
  Scene();
  ~Scene();

  void add_object(Object *obj) { objects.push_back(obj); }
  double min_dist_from_point(const Vector3 point);

  Camera *get_camera() { return camera; }
  std::vector<Object *> get_objects() { return objects; }
  void set_camera(Camera *arg) {
    delete camera;
    camera = arg;
  }
  void set_objects(std::vector<Object *> arg) { objects = arg; }
};

#endif
