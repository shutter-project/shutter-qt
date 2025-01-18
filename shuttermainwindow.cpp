#include "shuttermainwindow.h"
#include "ui_shuttermainwindow.h"

ShutterMainWindow::ShutterMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ShutterMainWindow)
{
    ui->setupUi(this);
}

ShutterMainWindow::~ShutterMainWindow()
{
    delete ui;
}
