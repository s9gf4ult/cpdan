#ifndef CPDANWINDOW_H
#define CPDANWINDOW_H

#include <QMainWindow>

namespace Ui {
class CPDanWindow;
}

class CPDanWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit CPDanWindow(QWidget *parent = 0);
    ~CPDanWindow();
    
private:
    Ui::CPDanWindow *ui;
};

#endif // CPDANWINDOW_H
