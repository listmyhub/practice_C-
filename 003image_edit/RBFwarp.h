#ifndef RBFWARP_H
#define RBFWARP_H
#include "basewarp.h"

class RBFwarp:public basewarp{
public:
    RBFwarp() {};
    ~RBFwarp() {};
public:
    QImage warp(QImage&src,QVector<QPointF>&srcpts,QVector<QPointF>&dstpts);
    double basefunc(double r);
};
#endif // RBFWARP_H
