#include <math.h>
#include <ncurses.h>

#include "Camera.hpp"
#include "Quaternion.hpp"
#include "Render.hpp"
#include "Scene.hpp"
#include "Sphere.hpp"
#include "Torus.hpp"
#include "Vector3.hpp"
#include "Window.hpp"

void build_scene(Scene *scene) {
  Torus *tor1 = new Torus(Vector3(40, 0, 0), 6, 3,
                          Vector3(-1 * sqrt(2) / 2, 0, sqrt(2) / 2), 0);
  scene->add_object(tor1);

  Sphere *sphere1 = new Sphere(Vector3(30, 0, 6), 3, 0);
  scene->add_object(sphere1);

  Sphere *sphere2 = new Sphere(Vector3(30, -10, 0), 3, 0);
  scene->add_object(sphere2);

  Sphere *sphere3 = new Sphere(Vector3(28, 7, 2), 3, 0);
  scene->add_object(sphere3);

  /*
  Torus *tor1 = new Torus(Vector3(10, 0, 0), 10, 3, Vector3(-1, 0, 0), 0);
  scene->add_object(tor1);

  Sphere *sphere1 = new Sphere(Vector3(0, 0, 4), 3);
  scene->add_object(sphere1);
  Sphere *sphere2 = new Sphere(Vector3(10, -10, 0), 3);
  scene->add_object(sphere2);
  Sphere *sphere3 = new Sphere(Vector3(8, 7, 2), 3);
  scene->add_object(sphere3);
  */
}

int main(int argc, char **argv) {
  initscr();
  noecho();
  timeout(0);
  keypad(stdscr, TRUE);

  bool running = true;

  Window window =
      Window(Vector2(0, 0), Vector2(getmaxx(stdscr), getmaxy(stdscr)));

  Render *render = new Render(window);

  Scene *scene = new Scene();

  build_scene(scene);

  Camera *camera =
      new Camera(Vector3(0, 0, 0), Vector3(1, -0.5, 9.d / 16.d / 2),
                 Vector2(1, 9.d / 16.d));

  scene->set_camera(camera);

  int cur_obj_num = 0;

  while (running) {
    switch (getch()) {
    case 'q':
      running = false;
      break;
    case KEY_UP:
      scene->get_objects()[cur_obj_num]->translate(Vector3(1, 0, 0));
      break;
    case KEY_DOWN:
      scene->get_objects()[cur_obj_num]->translate(Vector3(-1, 0, 0));
      break;
    case KEY_LEFT:
      scene->get_objects()[cur_obj_num]->translate(Vector3(0, -1, 0));
      break;
    case KEY_RIGHT:
      scene->get_objects()[cur_obj_num]->translate(Vector3(0, 1, 0));
      break;
    case ' ':
      scene->get_objects()[cur_obj_num]->translate(Vector3(0, 0, 1));
      break;
    case 'c':
      scene->get_objects()[cur_obj_num]->translate(Vector3(0, 0, -1));
      break;
    case '\t':
      cur_obj_num += 1;
      if (cur_obj_num >= scene->get_objects().size()) {
        cur_obj_num = 0;
      }
      break;
    case 'r':
      double ang = 5 * 3.14 / 180;
      Quaternion quat = Quaternion(cos(ang), Vector3(sin(ang), 0, 0));
      scene->get_objects()[cur_obj_num]->rotate_around(Vector3(0, 0, 0), quat);
      break;
    }

    render->draw(scene);
  }

  endwin();

  return 0;
}
