#include"Ellipse.h"

Ellipse::Ellipse(){
};
Ellipse::~Ellipse(){

};
void Ellipse::Draw(QPainter&painter){
    QRect rect(start,end);
    painter.drawEllipse(rect);
};