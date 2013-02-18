#ifndef MITHREAD_H
#define MITHREAD_H

#include <QThread>
#include <QDebug>
#include <cmath>

class MiThread:public QThread
{
    Q_OBJECT
public:
    explicit MiThread(QObject* parent);
    MiThread(){}
    MiThread(int a[], int i, int f, int flo, int top, QObject* parent);
    void run();
    long getId()const {return id;}
private:
    int ini;
    int fin;
    int floor;
    int top;
    int* arr;
    long id;
signals:
    void newString(QString mensaje);
    void newInt(int);
    void iFinished();
public slots:
    void emitFinished(){deleteLater();emit iFinished();}
};

#endif // MITHREAD_H
