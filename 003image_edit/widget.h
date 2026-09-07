#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"basewarp.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;
public:
    void paintEvent(QPaintEvent*event);
    void mousePressEvent(QMouseEvent*event);
    void mouseMoveEvent(QMouseEvent*event);
    void mouseReleaseEvent(QMouseEvent*event);
public slots:
    void open_();
    void save_();
    void IDW_();
    void RBF_();
   // void switch_();
    void clear_();
private:
    Ui::Widget *ui;
    QVector<QPointF> srcpts;
    QVector<QPointF> dstpts;
    QVector<QPointF> imagepts;
    int current;
    QImage srcimage;
    QImage showimage;
   // bool select_src;
    bool status_mouse;
    basewarp*warp_;
};
#endif // WIDGET_H
