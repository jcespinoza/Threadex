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
    MiThread(int a[], int i, int f, int flo, int top, QObject* parent);
    void run();
private:
    int ini;
    int fin;
    int floor;
    int top;
    int* arr;
signals:
    void newString(QString mensaje);
    void newInt(int);
public slots:
};

#endif // MITHREAD_H
