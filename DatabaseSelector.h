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
    enum DBType {Sqlite,
                 Postgresql};


    explicit DatabaseSelector(QWidget *parent, bool create);
    enum DBType getDbType();
    QString getSqliteFilename();

    ~DatabaseSelector();


public slots:
    void sqliteFileSelected();
    void onTabChanged(int tab);
    
private:
    Ui::DatabaseSelector *ui;
    bool dialogCreate;

    enum DBType dbtype;
    QString sqlite_filename;
};

#endif // DATABASESELECTOR_H
