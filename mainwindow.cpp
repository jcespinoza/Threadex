#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    counter = 0;
    maxCount = 5;
    size = 10000;
    arreglo = new int[size];
    threads = new MiThread*[5];

    threads[0] = new MiThread(arreglo, 0, 2000, 0, 1, this);
    threads[1] = new MiThread(arreglo, 2001, 4000, 100, 999, this);
    threads[2] = new MiThread(arreglo, 4001, 6000, 1000, 9999, this);
    threads[3] = new MiThread(arreglo, 6001, 8000, 10000, 99999, this);
    threads[4] = new MiThread(arreglo, 8001, 9999, 200, 300, this);

    tConnect();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete []arreglo;
    delete [] threads;
}

void MainWindow::addText(QString m){
    ui->teTexto->append(m);
}

void MainWindow::on_pbAgregar_clicked()
{
    addText("Desde el Main window...");
}

void MainWindow::increment(){
    counter++;
    if(counter == maxCount)
        emit counterMaxReached();
}

void MainWindow::showArray(){
    qDebug() << "All threads finished";
    for(int i = 0; i < size; i++){
        ui->teTexto->append(QString().setNum(arreglo[i]));
    }
}

void MainWindow::on_pbStart_clicked()
{
    if(counter > 0)
        return;
    else
        counter = 0;
    ui->teTexto->clear();
    for(int i = 0; i < maxCount; i++){
        threads[i]->start();
    }
}

void MainWindow::tConnect(){
    for(int i = 0; i < maxCount; i++)
        connect(threads[i], SIGNAL(iFinished()), this, SLOT(increment()));

    connect(this, SIGNAL(counterMaxReached()), this, SLOT(showArray()));
    connect(ui->pbClean, SIGNAL(clicked()), ui->teTexto, SLOT(clear()));
}
