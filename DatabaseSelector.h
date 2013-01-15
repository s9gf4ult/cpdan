#ifndef DATABASESELECTOR_H
#define DATABASESELECTOR_H

#include <QDialog>

namespace Ui {
class DatabaseSelector;
}

class DatabaseSelector : public QDialog
{
    Q_OBJECT
    
public:
    explicit DatabaseSelector(QWidget *parent = 0);
    ~DatabaseSelector();
    
private:
    Ui::DatabaseSelector *ui;
};

#endif // DATABASESELECTOR_H
