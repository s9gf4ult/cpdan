#include "CPDanWindow.h"
#include "ui_CPDanWindow.h"
#include <QMessageBox>
#include "DatabaseSelector.h"
#include "dbmanager.h"
#include <QtSql>

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

void CPDanWindow::createSqliteDatabase(QString filename) {
    QSqlDatabase *db = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
    db->setDatabaseName(filename);
    if (db->open()) {
        database=db;
        DBManager::createTables(database);
    } else {
        db->close();
        delete db;
        QMessageBox mb(this);
        mb.setModal(true);
        mb.setText(tr("Error while opening sqlite file"));
        mb.setIcon(QMessageBox::Critical);
        mb.exec();
    }
}

void CPDanWindow::createDatabase() {
    this->tryCloseDatabase();
    if (!this->database) {
        DatabaseSelector dbselector(this, true);
        dbselector.setModal(true);
        dbselector.exec();
        if (dbselector.getDbType() == DatabaseSelector::Sqlite &&
            dbselector.getSqliteFilename().length() > 0) {
            createSqliteDatabase(dbselector.getSqliteFilename());
        }
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
