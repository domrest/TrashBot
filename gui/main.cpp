
#include "mainwindow.h"
#include <iostream>
#include <QApplication>
using namespace std;
#include <unistd.h>
#include <pthread.h>

void *run(void *ptr){
   MainWindow *w= (MainWindow*) ptr;
 sleep(10);
    w->setTemp(20.0,20.0);
    sleep(2);
    w->setTemp(50,50);
}


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;

   // w.resize(800, 600); //for  smaller window
    w.resize(600,400);  //for maximized window

    pthread_t thread;

    w.show();
   int r1= pthread_create(&thread, NULL, run, (void*) &w);
    //w.startTimer(40);
    //return

      w.setTemp(70.0,70.0);
      //sleep(2);
      //w.setTemp(50,50);
    a.exec();
      return 1;
}

