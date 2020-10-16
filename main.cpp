#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("tic-tac-toe");
    w.setMinimumSize(500, 500);
    w.setMaximumSize(500, 500);
    w.show();
    return a.exec();
}
