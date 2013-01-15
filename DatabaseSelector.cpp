#include "DatabaseSelector.h"
#include "ui_DatabaseSelector.h"

DatabaseSelector::DatabaseSelector(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DatabaseSelector)
{
    ui->setupUi(this);
}

DatabaseSelector::~DatabaseSelector()
{
    delete ui;
}
