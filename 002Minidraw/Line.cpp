#include"Line.h"
#include<QDebug>

Line::Line(){
};
Line::~Line(){
    qDebug()<<"Line析构完毕";
};
void Line::Draw(QPainter&painter){
    painter.drawLine(start,end);
}