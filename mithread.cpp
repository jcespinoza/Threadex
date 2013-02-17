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
}

void MiThread::run(){
    qDebug() << "Threan::run";

    //QString id;
    //id.setNum((long)QThread::currentThread());
    id = (long)QThread::currentThread();
    for(int i = ini; i <= fin; i++){
        QString temp;
        //temp.setNum(i);
        //temp.setNum(rand() % (top - floor) + floor );
        int r = rand() + i;
        int gen = (r%(top+1-floor))+floor;
        temp.setNum(gen);
        qDebug() << "gen was constructed with" << r << "%(" << top << " + 1 ) +" << floor;
        qDebug() << "Writing" << gen << "to position" << i << ". Floor was" << floor << "and Top was" << top;
        arr[i] = gen;

        //emit newString("Agregando ThreadID:" + id + "-- Valor:" + temp);
        //sleep(1);
    }
;}

/*imprimir(ARREGLO,N);
 *qSort(ARREGLO+%,ARREGLO+N);
 *cout << "despues "
 *QTime t;
 *t.start();
 *metodo(ARREGLO,N);
 *qDebug() << "elapsed."
 *
*/
