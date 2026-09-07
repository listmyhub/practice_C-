#include "minidraw.h"
#include "ui_minidraw.h"
#include<QToolBar>

MiniDraw::MiniDraw(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MiniDraw)
{
    ui->setupUi(this);
    view_widget = new ViewWidget();
    createbuttons(); 
    setCentralWidget(view_widget);
}

MiniDraw::~MiniDraw()
{
    delete ui;
}
void MiniDraw::createbuttons() {
    //创建动作
    action_mouse1 = new QAction(tr("&Line"), this);
    connect(action_mouse1, &QAction::triggered, view_widget, &ViewWidget::set_Line);
    action_mouse2 = new QAction(tr("&Ellipse"), this);
    connect(action_mouse2, &QAction::triggered, view_widget, &ViewWidget::set_Ellipse);
    action_mouse3 = new QAction(tr("&Rectangle"), this);
    connect(action_mouse3, &QAction::triggered, view_widget, &ViewWidget::set_Rect);
    action_mouse4 = new QAction(tr("&Polygon"), this);
    connect(action_mouse4, &QAction::triggered, view_widget, &ViewWidget::set_Poly);
    action_clear = new QAction(tr("&Clear"), this);
    connect(action_clear, &QAction::triggered, view_widget, &ViewWidget::set_Clear);
    menu_mouse = menuBar()->addMenu(tr("&Figure tool"));
    menu_mouse->addAction(action_mouse1);
    menu_mouse->addAction(action_mouse2);
    menu_mouse->addAction(action_mouse3);
    menu_mouse->addAction(action_mouse4);
    menu_mouse->addAction(action_clear);
    tool_mouse=addToolBar(tr("Main"));
    tool_mouse->addAction(action_mouse1);
    tool_mouse->addAction(action_mouse2);
    tool_mouse->addAction(action_mouse3);
    tool_mouse->addAction(action_mouse4);
    tool_mouse->addAction(action_clear);
}
    
    
