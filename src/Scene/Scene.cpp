#include "Scene.hpp"

Scene::Scene() {
  camera = new Camera(Vector3(0, 0, 0), Vector3(0.5, -0.5, 0.5), Vector2(1, 1));
  objects = std::vector<Object *>();
}

Scene::~Scene() { delete camera; }

double Scene::min_dist_from_point(const Vector3 point) {
  double min_dist = 9999999999999999.0;
  for (int i = 0; i < objects.size(); i++) {
    DistanceEstimator *distance_estimator =
        objects[i]->get_distance_estimator();
    double cur_object_dist = distance_estimator->get_distance(point);
    delete distance_estimator;
    if (cur_object_dist < min_dist) {
      min_dist = cur_object_dist;
    }
  }
  return min_dist;
}
