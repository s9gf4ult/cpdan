#include "CPDanWindow.h"
#include "ui_CPDanWindow.h"
#include <QMessageBox>

CPDanWindow::CPDanWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CPDanWindow),
    database(0)
{
    ui->setupUi(this);
    QObject::connect(ui->actionCreate_DB,
                     SIGNAL(triggered()),
                     this,
                     SLOT(createDatabase()));
}

CPDanWindow::~CPDanWindow()
{
    delete ui;
    if (database) {
        this->closeDatabase();
    }
}

void CPDanWindow::tryCloseDatabase() {
    if (this->database) {
        QMessageBox mb(this);
        mb.setText(tr("There is one database is opened already, close it not ?"));
        mb.addButton(QMessageBox::Yes);
        mb.addButton(QMessageBox::No);
        if (mb.exec() == QMessageBox::Yes) {
            this->closeDatabase();
        }
    }
}

void CPDanWindow::createDatabase() {
    this->tryCloseDatabase();
    if (!this->database) {


    }
 }

void CPDanWindow::openDatabase() {
    this->tryCloseDatabase();
    if (!this->database) {

    }
}

void CPDanWindow::closeDatabase() {
    if (database) {
        database->close();
        delete database;
        database = 0;
    }
}
