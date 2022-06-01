#include "Render.hpp"

Ray Render::ray_from_screen_cords(Scene *scene, const Vector2 cords)
{
    Vector3 a = scene->get_camera()->screen_position;
    Vector2 b = scene->get_camera()->screen_size;
    double x_offset = cords.x / window.size.x;
    double y_offset = -cords.y / window.size.y;
    Vector3 pos = Vector3(a.x, a.y+ x_offset * b.x, a.z + y_offset * b.y);
    Vector3 dir = pos - scene->get_camera()->position;

    return Ray(pos, dir);    
}

double Render::raymarch(Scene *scene, Ray ray)
{
    double min_dist = scene->min_dist_from_point(ray.get_position());
    double dist = min_dist;
    int step = 0;
    while ((dist < 80) && (min_dist > 0.00001))
    {
        step++;
        ray.set_position(ray.get_position() + ray.get_direction() * min_dist);
        min_dist = scene->min_dist_from_point(ray.get_position());
        dist += min_dist;
    }
    return dist;
}

char ch[] = "#@$%=+;:-,. ";
char ch1[] = "@QB#NgWM8RDHdOKq9$6khEPXwmeZaoS2yjufF]}{tx1zv7lciL/\\|?*>r^;:_\"~,'.-` ";
void Render::draw(Scene *scene)
{
    move(window.position.x, window.position.y);

    for (int y = 0; y < (int)window.size.y; y++){
        for (int x = 0; x < (int)window.size.x; x++){
            double dist = raymarch(scene, ray_from_screen_cords(scene, Vector2(x, y)));
            if (dist > 80){
                dist = 80;
            }
            addch(ch1[(int)(dist / 80.d * 68)]);
        }
    }

    refresh();
}
