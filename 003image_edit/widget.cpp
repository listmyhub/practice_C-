#include "widget.h"
#include "./ui_widget.h"
#include<QFileDialog>
#include<iostream>
#include<QMouseEvent>
#include<QPainter>
#include<QMessageBox>
#include"idwwarp.h"
#include"RBFwarp.h"
#include"basewarp.h"
using namespace std;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //select_src=true;
    status_mouse = false;
    current = -1;
    srcpts.clear();
    dstpts.clear();
}

Widget::~Widget()
{
    delete ui;
}
void Widget::open_(){
    //open file
    QString file_=QFileDialog::getOpenFileName(this,tr("Read Image"),".",tr("Images(*.bmp *.png *.jpg"));
    //load file
    if(!file_.isEmpty()){
       srcimage.load(file_);
       showimage=srcimage;
       srcpts.clear();
       dstpts.clear();
       //select_src=true;
    }
    cout<<"image size:"<<srcimage.width()<<srcimage.height()<<endl;
    update();
}
void Widget::save_(){
    QString file_=QFileDialog::getSaveFileName(this,tr("Read Image"),".",tr("Images(*.bmp *.png *.jpg"));
    if(file_.isEmpty()){
        return;
    }
    showimage.save(file_);
}
void Widget::clear_(){
    srcpts.clear();
    dstpts.clear();
    current = -1;
    status_mouse = false;
    //select_src=true;
    showimage=srcimage;
    update();
}
/*void Widget::switch_() {
    select_src=false;
    QMessageBox::information(this,"通知","可以选目标点了");
}*/
void Widget::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        srcpts.push_back(event->pos());
        dstpts.push_back(event->pos());
        current++;
        status_mouse = true;
        update();
    }
}
void Widget::mouseMoveEvent(QMouseEvent* event) {
    if (status_mouse) {
        dstpts[current]=event->pos();
        update();
    }
}
void Widget::mouseReleaseEvent(QMouseEvent* event) {
    status_mouse = false;
    if (srcpts[current].x() < 0 || srcpts[current].y() < 0 || srcpts[current].x() > width() || srcpts[current].y() > height() ||
        dstpts[current].x() < 0 || dstpts[current].y() < 0 || dstpts[current].x() > width() || dstpts[current].y() > height()) {
        srcpts.pop_back();
        dstpts.pop_back();
        current--;
        update();
    }
}
       

    /*if (srcimage.isNull()) {
        return;
    }
    if(select_src){
        srcpts.push_back(event->pos());
    }
    else{
        dstpts.push_back(event->pos());
    }
    select_src = true;
    update();*/
void Widget::paintEvent(QPaintEvent*event){
    QPainter p(this);
    p.setBrush(Qt::lightGray);
    QRect rect(0, 0, width(), height());
    p.drawRect(rect);
    QRect rect1(0,0, showimage.width(), showimage.height());
    p.drawImage(rect1,showimage);
    if (showimage.isNull()){
        return;
    }
    //set yuandian red
    p.setPen(QPen(Qt::red, 6));
    for (int i = 0;i < srcpts.size();i++) {
        p.drawLine(srcpts[i], dstpts[i]);
    }
   
    /*for (auto& a : srcpts) {
        p.drawPoint(a);
    }
    //set control blue
    p.setPen(QPen(Qt::blue,6));
    for (auto&b:dstpts){
        p.drawPoint(b);
    }*/
}
void Widget::IDW_(){
    if(srcpts.size()!=dstpts.size()||srcpts.isEmpty()){
        QMessageBox::warning(this,"错误","控制点数不一致或未选点");
        return;
    }
    warp_=new idwwarp();
    showimage=warp_->warp(srcimage,srcpts,dstpts);
    delete warp_;
    update();
}
void Widget::RBF_(){
    if(srcpts.size()!=dstpts.size()||srcpts.size()<3){
        QMessageBox::warning(this,"错误","控制点数不一致或RBF至少需要三个点");
        return;
    }
    warp_=new RBFwarp();
    showimage=warp_->warp(srcimage,srcpts,dstpts);
    delete warp_;
    update();
}
