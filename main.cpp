#include "mainwindow.h"

#include <QApplication>
#include <QStyle>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    hide menu bar
    w.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
//    set opacity
    w.setProperty("windowOpacity", 0.8);
//    center the main window
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-w.width()) / 2;
    int y = (screenGeometry.height()-w.height()) / 2;
    w.move(x, y);
    w.show();
    return a.exec();
}
