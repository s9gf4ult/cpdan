#ifndef CPDANWINDOW_H
#define CPDANWINDOW_H

#include <QMainWindow>
#include <QtSql>

namespace Ui {
class CPDanWindow;
}

class CPDanWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit CPDanWindow(QWidget *parent = 0);
    ~CPDanWindow();

    void createSqliteDatabase(QString filename);
    void tryCloseDatabase();

public slots:
    void createDatabase();
    void openDatabase();
    void closeDatabase();
    
private:
    Ui::CPDanWindow *ui;
    QSqlDatabase *database;
};

#endif // CPDANWINDOW_H
