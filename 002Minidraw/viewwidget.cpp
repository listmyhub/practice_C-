#include "viewwidget.h"
#include "ui_viewwidget.h"
#include"Line.h"
#include"Ellipse.h"
#include"Rect.h"
#include"Poly.h"
#include<QInputDialog>

ViewWidget::ViewWidget(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    shape_=NULL;
    point_status=false;
    st=Shape::kdefault;
    isDrawing = false;
    size_poly = 5;
}

ViewWidget::~ViewWidget()
{
    for (int i = 0;i< array_list.size();i++) {
        delete array_list[i];
    }
    qDebug() << "array_list析构，内存已释放";
    array_list.clear();
    if (shape_ != NULL) {
        delete shape_;
        shape_ = NULL;
    }
    vertices.clear();
    qDebug()<<"ViewWidget析构，内存已释放";
}
void ViewWidget::mousePressEvent(QMouseEvent*event){
    if(event->button()==Qt::LeftButton){
        switch(st){
        case Shape::kdefault:
            break;
        case Shape::kLine:
            shape_=new Line();
            break;
        case Shape::kEllipse:
            shape_=new Ellipse();
            break;
        case Shape::kRec:
            shape_=new Rect();
            break;
        case Shape::kPoly:
            center=event->pos();
            isDrawing = true;
            break;
        };
        if (shape_ != NULL) {
            point_status = true;
            shape_->set_start(event->pos());
            shape_->set_end(event->pos());
        }
    }
    update();
};
void ViewWidget::mouseMoveEvent(QMouseEvent* event) {
    if (point_status && shape_ != NULL) {
        end_point = event->pos();
        shape_->set_end(end_point);
        update();
    }
    if (st == Shape::kPoly && isDrawing) {
        int rx = abs(event->pos().x() - center.x());
        int ry = abs(event->pos().y() - center.y());
        radius = sqrt(rx * rx + ry * ry);
        vertices =Poly::caculate_vertices(center, radius, size_poly);
        update();
    }
}
void ViewWidget::mouseReleaseEvent(QMouseEvent*event){
    if(shape_!=NULL){
        point_status=false;
        array_list.push_back(shape_);
        shape_=NULL;
        update();
    }
    if(st==Shape::kPoly&&isDrawing){
       Poly* poly = new Poly();
       poly->set_vertices(vertices);
       array_list.push_back(poly);
       isDrawing = false;
       poly=NULL;
       //delete poly;
       update();
    }
   
}
void ViewWidget::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    for (int i = 0;i<array_list.size();i++) {
        array_list[i]->Draw(painter);
    }
    if (shape_ != NULL) {
        shape_->Draw(painter);
    }
    if (st == Shape::kPoly && isDrawing && vertices.size() >= 2) {
        QPolygon polygon(vertices);
        painter.drawPolygon(polygon);
    }
};
void ViewWidget::set_Line(){
    st=Shape::kLine;
}
void ViewWidget::set_Ellipse(){
    st=Shape::kEllipse;
}
void ViewWidget::set_Rect(){
    st=Shape::kRec;
}
void ViewWidget::set_Poly(){
    st=Shape::kPoly;
    bool ok;
    size_poly = QInputDialog::getInt(this, "正多边形", "请输入边数（3-20）:", 5, 3, 20, 1, &ok);
}
void ViewWidget::set_Clear(){
    for(Shape*shape_:array_list){
        delete shape_;
    }    
    array_list.clear();
    if(shape_!=NULL){
        delete shape_;
        shape_=NULL;
    }
    vertices.clear();
    point_status=false;
    isDrawing = false;
    update();
}

