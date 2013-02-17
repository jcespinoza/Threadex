#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    counter = 0;
    maxCount = 5;
    this->thread()->sleep(3);
    //initThreads();
    size = 10;
    arreglo = new int[size];
    MiThread* te = new MiThread(arreglo, 0, 1, 0, 1, this);
    te->start();
    connect(te, SIGNAL(iFinished()), this, SLOT(increment()));
    MiThread* de = new MiThread(arreglo, 2, 3, 11, 20, this);
    de->start();
    connect(de, SIGNAL(iFinished()), this, SLOT(increment()));
    MiThread* se = new MiThread(arreglo, 4, 5, 21, 30, this);
    se->start();
    connect(se, SIGNAL(iFinished()), this, SLOT(increment()));
    MiThread* we = new MiThread(arreglo, 6, 7, 31, 40, this);
    we->start();
    connect(we, SIGNAL(iFinished()), this, SLOT(increment()));
    MiThread* qe = new MiThread(arreglo, 8, 9, 41, 50, this);
    qe->start();
    connect(qe, SIGNAL(iFinished()), this, SLOT(increment()));
    connect(this, SIGNAL(counterMaxReached()), this, SLOT(showArray()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete []arreglo;
//    delete [] threads;
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

void MainWindow::increment(){
    counter++;
    if(counter == maxCount)
        emit counterMaxReached();
}

void MainWindow::showArray(){
    qDebug() << "All threads finished";
    for(int i = 0; i < size; i++){
        qDebug() << i << " -> " << arreglo[i];
        ui->teTexto->append(QString().setNum(arreglo[i]));
    }
}

void MainWindow::initThreads(){
    int parts = maxCount;
    int interval;
    //threads = new MiThread[maxCount];
    for(int i = 0; i < 10; i++){
        int begin = size*i/parts - size/parts;
        int end = size*i/parts;
        //threads[i] = new MiThread(arreglo, )
    }
}
