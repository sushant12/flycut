#include "mainwindow.h"

#include <QApplication>
#include <QStyle>
#include <QDesktopWidget>
#include <QClipboard>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QClipboard *clipboard =  QGuiApplication::clipboard();
    QString text = clipboard->text();

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
    QLabel *label = new QLabel(&w);
    label->setText(clipboard->text());
    w.show();
    return a.exec();
}
