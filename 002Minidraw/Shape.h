#ifndef SHAPE_H
#define SHAPE_H
#include <QPainter>
class Shape{
public:
    Shape();
    virtual ~Shape();
    virtual void Draw(QPainter&paint)=0;
    void set_start(QPoint s);
    void set_end(QPoint e);
public:
    enum Shape_type{
        kdefault=0,
        kLine=1,
        kEllipse=2,
        kRec=3,
        kPoly=4
    };
protected:
    QPoint start;
    QPoint end;
};

#endif // SHAPE_H
