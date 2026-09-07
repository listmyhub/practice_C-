#ifndef IDWWARP_H
#define IDWWARP_H
#include"basewarp.h"

class idwwarp:public basewarp{
public:
    idwwarp(){};
    ~idwwarp(){};
public:
    QImage warp(QImage&src,QVector<QPointF>&srcpts,QVector<QPointF>&dstpts)override;
};

#endif // IDWWARP_H
