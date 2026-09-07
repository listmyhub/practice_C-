#include "Shape.h"
#include <QDebug>
Shape::Shape(){
};
Shape::~Shape(){
    qDebug()<<"Shape完毕";
};
void Shape::set_start(QPoint s){
    start=s;
};
void Shape::set_end(QPoint e){
    end=e;
};