#include "point.h"
#include <iostream>
#include <cassert>

point::point(){
    x=0;
    y=0;
    c=BLUE;
}

point::point(int x1, int y1, Color c1){
    x=x1;
    y=y1;
    c=c1;
}

point::point(const point& p){
    x=p.x;
    y=p.y;
    c=p.c;
}
