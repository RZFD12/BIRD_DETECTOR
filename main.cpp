#include "mainwindow.h"
#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qApp->setStyle("Fusion");
    QFile file("./themes/Ubuntu.qss");
    file.open(QFile::ReadOnly);
    qApp->setStyleSheet(QString::fromLatin1(file.readAll()));
    MainWindow w;
    w.setMinimumSize(1024, 576);
    w.setWindowState(Qt::WindowMaximized);
    w.show();
    return a.exec();
}
