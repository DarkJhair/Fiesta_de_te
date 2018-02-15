#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonBuscar_clicked()
{
    QFile file("C:/Unitec/Estructura de Datos 1 (segundo intento)/Fiesta de te/Proyecto/Proyecto/TwitterPrueba/tweets.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        ui->textEditTweets->append("No sirve");
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        ui->textEditTweets->append(line);
    }
    file.close();

    /*
    ifstream in("TwitterPrueba/tweets.txt");
    string lectura;
    while(in>>lectura){
        ui->textEditTweets->append("Nisiquiera llegue aqui");
        QString str = QString::fromLocal8Bit(lectura.c_str());
        ui->textEditTweets->append(str);
        ui->textEditTweets->append("Nisiquiera llegue aqui");
    }
    in.close();
    */
}
