#ifndef MINIDRAW_H
#define MINIDRAW_H

#include <QtWidgets/QMainWindow>
#include"viewwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MiniDraw;
}
QT_END_NAMESPACE

class MiniDraw : public QMainWindow
{
    Q_OBJECT

public:
    explicit MiniDraw(QWidget *parent = nullptr);
    ~MiniDraw() override;
public:
    QAction* action_mouse1;
    QAction* action_mouse2;
    QAction* action_mouse3;
    QAction* action_mouse4;
    QAction*action_clear;
    QMenu* menu_mouse;
    QToolBar* tool_mouse;
    void createbuttons();
    ViewWidget* view_widget;
private:
    Ui::MiniDraw *ui;
};
#endif // MINIDRAW_H
