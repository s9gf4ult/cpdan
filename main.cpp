#include "CPDanWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CPDanWindow w;
    w.show();
    
    return a.exec();
}
