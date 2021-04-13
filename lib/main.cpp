//
// Created by domrest on 20/03/2021.
//

#include "../include/GPIO/tsic.h"
#include <iostream>
#include <unistd.h>
#include "../include/GUI/mainwindow.h"
#include <iostream>
#include <QApplication>

using namespace std;


void initDetectors(Messaging* messaging, MainWindow* window){
    TempDetector* detectors = new TempDetector(messaging, window);

    cout << "Initializing Detectors"<<endl;

    TSIC* detector1 = new TSIC(detectors->temp1, detectors->valid1, detectors);
    detector1->open(23);
    TSIC* detector2 = new TSIC(detectors->temp2, detectors->valid2, detectors);
    detector2->open(24);
    cout << "Detectors opened"<<endl;
}

int main(){
    QApplication a(argc, argv);
    MainWindow w;
    cout << "Start"<<endl;
    Messaging* messaging = new Messaging();
    cout << "Initialised Messaging"<<endl;


    initDetectors(messaging, window);
    messaging->startup();

    w.resize(600,400);
    w.show();
    w.setTemp(0.0,0.0);
    return a.exec();
}