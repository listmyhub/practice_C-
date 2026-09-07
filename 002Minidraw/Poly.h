#ifndef POLY_H
#define POLY_H
#include"Shape.h"
#include<cmath>
#include<QVector>

class Poly :public Shape {
public:
    Poly();
    ~Poly();
    void Draw(QPainter& painter);
    static QVector<QPoint > caculate_vertices(QPoint center, double radius, int side_poly);
    void set_vertices(QVector<QPoint > vertices);
public:
    QVector<QPoint > vertices;
};
#endif // POLY_H
