#include <ncurses.h>
#include <math.h>

#include "Vector3.hpp"
#include "Camera.hpp"
#include "Render.hpp"
#include "Scene.hpp"
#include "Sphere.hpp"
#include "Torus.hpp"
#include "Window.hpp"
#include "Quaternion.hpp"

void build_scene(Scene *scene)
{
    Torus *tor1 = new Torus(Vector3(0, 0, 0), 10, 3, Vector3(-sqrt(2) / 2, 0, sqrt(2) / 2));
    scene->add_object(tor1);
    Sphere *sphere1 = new Sphere(Vector3(0, 0, 4), 3);
    scene->add_object(sphere1);
    Sphere *sphere2 = new Sphere(Vector3(10, -10, 0), 3);
    scene->add_object(sphere2);
    Sphere *sphere3 = new Sphere(Vector3(8, 7, 2), 3);
    scene->add_object(sphere3);
}

int main(int argc, char **argv)
{
    initscr();
    noecho();
    timeout(0);
    keypad(stdscr, TRUE);

    bool runing = true;

    Window window = Window(Vector2(0, 0), Vector2(getmaxx(stdscr), getmaxy(stdscr)));

    Render *render = new Render(window);

    Scene *scene = new Scene();

    build_scene(scene);
    
    Camera *camera = new Camera(Vector3(-10.5, 0, 0),
                                  Vector3(-10, -0.5, 9.d / 16.d / 2),
                                  Vector2(1, 9.d / 16.d));

    scene->set_camera(camera);

    int cur_obj_num = 0;
    
    Vector3 pos = Vector3(0, 0, 0);
    while(runing) {
        switch (getch()) {
        case 'q':
            runing = false;
            break;
        case KEY_UP:
            pos = scene->get_objects()[cur_obj_num]->get_position() + 
                Vector3(1, 0, 0);
            scene->get_objects()[cur_obj_num]->set_position(pos);
            break;
        case KEY_DOWN:
            pos = scene->get_objects()[cur_obj_num]->get_position() + 
                Vector3(-1, 0, 0);
            scene->get_objects()[cur_obj_num]->set_position(pos);
            break;
        case KEY_LEFT:
            pos = scene->get_objects()[cur_obj_num]->get_position() + 
                Vector3(0, -1, 0);
            scene->get_objects()[cur_obj_num]->set_position(pos);
            break;
        case KEY_RIGHT:
            pos = scene->get_objects()[cur_obj_num]->get_position() + 
                Vector3(0, 1, 0);
            scene->get_objects()[cur_obj_num]->set_position(pos);
            break;
        case ' ':
            pos = scene->get_objects()[cur_obj_num]->get_position() + 
                Vector3(0, 0, 1);
            scene->get_objects()[cur_obj_num]->set_position(pos);
            break;
        case 'c':
            pos = scene->get_objects()[cur_obj_num]->get_position() + 
                Vector3(0, 0, -1);
            scene->get_objects()[cur_obj_num]->set_position(pos);
            break;
        case '\t':
            cur_obj_num += 1;
            if (cur_obj_num >= scene->get_objects().size()){
                cur_obj_num = 0;
            }
            break;
        case 'r':
            pos = scene->get_objects()[cur_obj_num]->get_position();
            pos = (Quaternion(0.707d, 0.707d, 0, 0) * Quaternion(pos) * 
                    Quaternion(0.707d, -0.707d, 0, 0)).im;
            scene->get_objects()[cur_obj_num]->set_position(pos);
            break;
        }

        render->draw(scene);
    }

    endwin();

    return 0;
}
