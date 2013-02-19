#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "mithread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void addText(QString);
    void increment();
    void on_pbAgregar_clicked();
    void showArray();
    void on_pbStart_clicked();

signals:
    void counterMaxReached();

private:
    Ui::MainWindow *ui;
    int* arreglo;
    int counter;
    int maxCount;
    int size;
    MiThread **threads;
    void initThreads();
    void tConnect();
};

#endif // MAINWINDOW_H
