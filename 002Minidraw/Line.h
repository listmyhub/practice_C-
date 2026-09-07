#ifndef LINE_H
#define LINE_H
#include "Shape.h"
class Line:public Shape{
public:
    Line();
    ~Line();
    void Draw(QPainter&painter);
};

#endif // LINE_H
