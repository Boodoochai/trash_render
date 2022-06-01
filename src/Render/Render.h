#ifndef RENDER_HEADER
#define RENDER_HEADER

#include <ncurses.h>

#include "Ray.h"
#include "Scene.h"
#include "Window.h"

class Render
{
public:
    Window window;
    
    Render(Window arg) : window(arg) {}

    Ray ray_from_screen_cords(Scene* scene, const Vector2 cords);
    double raymarch(Scene *scene, const Ray ray);
    void draw(Scene *scene);
};

#endif
