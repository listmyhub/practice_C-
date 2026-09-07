#ifndef VIEWWIDGET_H
#define VIEWWIDGET_H

#include <QWidget>
#include<QMouseEvent>
#include "Shape.h"
#include<vector>
#include "ui_ViewWidget.h"
#include<QVector>


class ViewWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ViewWidget(QWidget *parent = nullptr);
    ~ViewWidget() override;
public:
    void mousePressEvent(QMouseEvent* event)override;
    void mouseMoveEvent(QMouseEvent* event)override;
    void mouseReleaseEvent(QMouseEvent* event)override;
    void paintEvent(QPaintEvent*)override;
private:
    Ui::ViewWidget ui;
    QPoint start_point;
    QPoint end_point;
    Shape*shape_;
    Shape::Shape_type st;
    bool point_status;
    std::vector<Shape*> array_list;
    QPoint center;
    double radius;
    int size_poly;
    bool isDrawing;
    QVector<QPoint> vertices;
signals:
public slots:
    void set_Line();
    void set_Ellipse();
    void set_Rect();
    void set_Poly();
    void set_Clear();
};
#endif // VIEWWIDGET_H
