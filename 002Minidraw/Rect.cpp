#include"Rect.h"
#include<QDebug>
Rect::Rect(){
};
Rect::~Rect(){
    qDebug()<<"Rect析构函数";//输出析构完毕
};
void Rect::Draw(QPainter&painter){
    painter.drawRect(QRect(start,end));
}