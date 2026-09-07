#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"widget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
private:
    Ui::MainWindow *ui;
    QMenu *menu_file_;
    QMenu* menu_edit_;
    QAction *action_open_;
    QAction *action_save;
   // QAction* action_switch;
    QAction* action_IDW;
    QAction* action_RBF;
    QToolBar* tool_edit;
    QAction* action_clear;
    QToolBar *tool;
    Widget* widget_;
private:
    void create_action();
    void create_menu();
    void create_tool();
};
#endif // MAINWINDOW_H
