#include "mithread.h"
#include "ctime"

MiThread::MiThread(QObject *parent = 0){
    arr = 0;
    ini = fin = floor = top = 0;
}

MiThread::MiThread(int a[], int i, int f, int flo, int t, QObject* parent=0):QThread(parent)
{
    arr = a;
    ini = i;
    fin = f;
    floor = flo;
    top = t;
    connect(this, SIGNAL(finished()), this, SLOT(emitFinished()));
    //connect(this, SIGNAL(finished(QPrivateSignal)), this, SLOT(deleteLater()));
}

void MiThread::run(){
    id = (long)QThread::currentThread();
    for(int i = ini; i <= fin; i++){
        QString temp;
        int r = rand() + i;
        int gen = (r%(top+1-floor))+floor;
        temp.setNum(gen);

        arr[i] = gen;
    }
;}
