#pragma once

#include <Imagine/Graphics.h>
using namespace Imagine;

struct point {
    int x,y;
    Color c;

    //constructeurs
    point();
    point(int x1, int y1, Color c1);
    point(const point & p);
};
