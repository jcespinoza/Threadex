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
    
    void on_pbCrear_clicked();

    void on_pbAgregar_clicked();

private:
    Ui::MainWindow *ui;
    int* arreglo;
};

#endif // MAINWINDOW_H
