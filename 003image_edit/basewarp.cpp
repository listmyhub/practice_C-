#include"basewarp.h"

QRgb basewarp::bilinearInterp(QImage&img,float x,float y){
    int w=img.width();
    int h=img.height();
    x=qMax(0.0f,qMin((float)w-1,x));
    y=qMax(0.0f,qMin((float)h-1,y));
    int x0=static_cast<int>(floor(x));
    int y0=static_cast<int>(floor(y));
    int x1=qMin(x0+1,w-1);
    int y1=qMin(y0+1,h-1);
    float dx=x-x0;
    float dy=y-y0;
    QRgb p00=img.pixel(x0,y0);
    QRgb p01=img.pixel(x0,y1);
    QRgb p10=img.pixel(x1,y0);
    QRgb p11=img.pixel(x1,y1);
    int r=qRound(qRed(p00)*(1-dx)*(1-dy)+qRed(p01)*(1-dx)*dy+qRed(p10)*dx*(1-dy)+qRed(p11)*dx*dy);
    int g=qRound(qGreen(p00)*(1-dx)*(1-dy)+qGreen(p01)*(1-dx)*dy+qGreen(p10)*dx*(1-dy)+qGreen(p11)*dx*dy);
    int b=qRound(qBlue(p00)*(1-dx)*(1-dy)+qBlue(p01)*(1-dx)*dy+qBlue(p10)*dx*(1-dy)+qBlue(p11)*dx*dy);
    return qRgb(r,g,b);
}