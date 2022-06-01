#ifndef WINDOW_HEADER
#define WINDOW_HEADER

#include "Vector2.hpp"

struct Window
{
    Vector2 position;
    Vector2 size;

    Window(Vector2 arg1, Vector2 arg2) : position(arg1), size(arg2){}
};

#endif
