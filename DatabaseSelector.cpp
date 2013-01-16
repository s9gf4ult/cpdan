#include "DatabaseSelector.h"
#include "ui_DatabaseSelector.h"
#include <QFileDialog>

DatabaseSelector::DatabaseSelector(QWidget *parent, bool create) :
    QDialog(parent),
    ui(new Ui::DatabaseSelector),
    dialogCreate(create)
{
    ui->setupUi(this);
    QObject::connect(ui->selectSqlite,
                     SIGNAL(clicked()),
                     this,
                     SLOT(sqliteFileSelected()));

}

enum DatabaseSelector::DBType DatabaseSelector::getDbType() {
    return dbtype;
}

QString DatabaseSelector::getSqliteFilename() {
    return sqlite_filename;
}

DatabaseSelector::~DatabaseSelector()
{
    delete ui;
}

void DatabaseSelector::sqliteFileSelected() {
    QFileDialog fdiag(this);
    fdiag.setModal(true);
    if (dialogCreate) {
        fdiag.setAcceptMode(QFileDialog::AcceptSave);
    } else {
        fdiag.setAcceptMode(QFileDialog::AcceptOpen);
    }
    fdiag.exec();
    QStringList files=fdiag.selectedFiles();
    if (files.count()) {
        dbtype=DatabaseSelector::Sqlite;
        sqlite_filename=files.first();
        ui->sqliteFilename->setText(sqlite_filename);
    }
}

void DatabaseSelector::onTabChanged(int tab) {
    switch (tab) {
    case 0:
        dbtype=DatabaseSelector::Sqlite;
        break;
    case 1:
        dbtype=DatabaseSelector::Postgresql;
        break;
    }
}
