#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    arreglo = new int[1000000];
    MiThread* te = new MiThread(arreglo, 12, 13, 200, 600, this);
    te->start();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete []arreglo;
}

void MainWindow::addText(QString m){
    ui->teTexto->append(m);
}

void MainWindow::on_pbCrear_clicked()
{
    /*MiThread* apThread = new MiThread(this);
        connect(apThread, SIGNAL(newString(QString)), this, SLOT(addText(QString)));
    apThread->start();*/
}

void MainWindow::on_pbAgregar_clicked()
{
    addText("Desde el Main window...");
}
