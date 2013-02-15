#include "mithread.h"

MiThread::MiThread(int a[], int i, int f, int flo, int t, QObject* parent=0):QThread(parent)
{
    arr = a;
    ini = i;
    fin = f;
    floor = flo;
    top = t;
}

void MiThread::run(){
    qDebug() << "Threan::run";

    QString id;
    id.setNum((long)QThread::currentThread());
    for(int i = 0; i <= 20; i++){
        QString temp;
        //temp.setNum(i);
        temp.setNum((rand()* (top-floor) ) + floor);
        qDebug() << temp;

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
