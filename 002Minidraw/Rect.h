#ifndef RECT_H
#define RECT_H
#include "Shape.h"
class Rect:public Shape{
public:
    Rect();
    ~Rect();
    void Draw(QPainter&painter);
};

#endif // RECT_H
