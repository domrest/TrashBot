//
// Created by domrest on 27/03/2021.
//

#include <iostream>
#include "../messaging/Messaging.h"
#include "../GUI/mainwindow.h"


class TempDetector {

public:
    TempDetector(Messaging* messaging, MainWindow* window);

    ~TempDetector();

    void callBack();

    double* temp1;
    bool* valid1;
    double* temp2;
    bool* valid2;
    Messaging* messaging;
    MainWindow* window;
    bool* message1Sent;
    bool* message2Sent;
private:

};


