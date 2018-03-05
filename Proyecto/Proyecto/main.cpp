#include "mainwindow.h"
#include <QApplication>
#include <windows.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //system("java -jar TwitterPrueba/dist/TwitterPrueba.jar");
    //con el codigo de arriba se deberia de ejecutar el .jar
    return a.exec();
}
