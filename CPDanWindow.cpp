#include "CPDanWindow.h"
#include "ui_CPDanWindow.h"

CPDanWindow::CPDanWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CPDanWindow)
{
    ui->setupUi(this);
}

CPDanWindow::~CPDanWindow()
{
    delete ui;
}
