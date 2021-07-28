#include "mainwindow.h"

#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QRect Screen=QApplication::desktop()->availableGeometry();
    MainWindow w(nullptr, Screen);
    w.show();
    w.lwind=w.twind=w.wind=GetForegroundWindow();
    char* ab=new char[100];
    GetWindowTextA(w.lwind, ab, 100);
    w.T->start(1);
    delete[] ab;
    return a.exec();
}
