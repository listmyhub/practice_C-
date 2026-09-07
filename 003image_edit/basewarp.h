#ifndef BASEWARP_H
#define BASEWARP_H
#include <QImage>
#include<QVector>
#include<QPointF>

class basewarp{
public:
    basewarp(){
    }
    virtual ~basewarp(){}
public:
    //虚构变形接口
    virtual QImage warp(QImage& src, QVector<QPointF>& srcpts, QVector<QPointF>& dstpts)=0;
    //子类公用的插值函数
    QRgb bilinearInterp(QImage&img,float x,float y);
};

#endif // BASEWARP_H
