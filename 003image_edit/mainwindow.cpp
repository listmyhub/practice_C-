#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QToolBar>
#include"Widget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    widget_ = new Widget();
    setCentralWidget(widget_);
    create_action();
    create_menu();
    create_tool();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::create_action(){
    action_open_=new QAction(/*QIcon(":/MainWindow/Resources/images/open.jpg"), */ tr("&Open"), this);
    connect(action_open_, &QAction::triggered, widget_, &Widget::open_);
    action_save=new QAction(/*QIcon(":/MainWindow/Resources/images/save.jpg"), */ tr("&save"), this);
    connect(action_save, &QAction::triggered, widget_, &Widget::save_);
    //action_switch = new QAction(tr("&switch"), this);
    //connect(action_switch,&QAction::triggered, widget_, &Widget::switch_);
    action_IDW = new QAction(tr("IDW"), this);
    connect(action_IDW, &QAction::triggered, widget_, &Widget::IDW_);
    action_RBF = new QAction(tr("&RBF"), this);
    connect(action_RBF, &QAction::triggered, widget_, &Widget::RBF_);
    action_clear = new QAction(tr("clear"), this);
    connect(action_clear, &QAction::triggered, widget_, &Widget::clear_);
}
void MainWindow::create_menu(){
    menu_file_=menuBar()->addMenu(tr("&File"));
    menu_file_->addAction(action_open_);
    menu_file_->addAction(action_save);
    menu_edit_ = menuBar()->addMenu(tr("&Edit"));
   // menu_edit_->addAction(action_switch);
    menu_edit_->addAction(action_IDW);
    menu_edit_->addAction(action_RBF);
    menu_edit_->addAction(action_clear);
}
void MainWindow::create_tool(){
    tool=addToolBar(tr("&File"));
    tool->addAction(action_open_);
    tool->addAction(action_save);
    tool_edit = addToolBar(tr("&Edit"));
   // tool_edit->addAction(action_switch);
    tool_edit->addAction(action_IDW);
    tool_edit->addAction(action_RBF);
    tool_edit->addAction(action_clear);
}
