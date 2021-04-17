//
// Created by Domenico Restuccia on 27/03/2021.
//

#include "../include/GPIO/TempDetector.h"

using namespace std;

static const double THRESHOLD1 = 1.0;
static const double THRESHOLD2 = 4.0;


TempDetector::TempDetector(Messaging* _messaging, MainWindow* _window) {
    messaging = _messaging;
    window = _window;
    temp1 = (double *)(malloc(sizeof(double)));
    temp2 = (double *)(malloc(sizeof(double)));
    valid1 = (bool *)(malloc(sizeof(bool)));
    valid2 = (bool *)(malloc(sizeof(bool)));
    message1Sent = (bool *)(malloc(sizeof(bool)));
    message2Sent = (bool *)(malloc(sizeof(bool)));
    *message1Sent = false;
    *message2Sent = false;
}

TempDetector::~TempDetector() {
    free(temp1);
    free(temp2);
    free(valid1);
    free(valid2);
}


void TempDetector::callBack(){
    if (*valid1 && *valid2){
        if ((*temp1 - *temp2) > THRESHOLD1 && not *message1Sent){
            messaging->sendMessage1();
            *message1Sent = true;
        }
        if ((*temp1 - *temp2)< (THRESHOLD1 - 0.5) && *message1Sent){
            *message1Sent = false;
        }

        if ((*temp1 - *temp2) > THRESHOLD2 && not *message2Sent){
            messaging->sendMessage2();
            *message2Sent = true;
        }
        if ((*temp1 - *temp2)< (THRESHOLD2 - 0.5) && *message2Sent){
            *message2Sent = false;
        }
        window->setTemp(*temp1, *temp2);
        cout << "detector 1: "<< *temp1 <<endl;
        cout << "detector 2: "<< *temp2 <<endl;
    } else if (*valid2){
        window->setTemp(0.0, *temp2);
        cout << "detector 2: "<< *temp2 <<endl;
    } else if (*valid1){
        window->setTemp(*temp1, 0.0);
        cout << "detector 2: "<< *temp2 <<endl;
    }

    cout << endl << endl;
}
