//
// Created by domrest on 27/03/2021.
//

#include "../include/GPIO/TempDetector.h"

using namespace std;

static const double THRESHOLD = 0.5;

TempDetector::TempDetector(Messaging* _messaging) {
    messaging = _messaging;
    temp1 = (double *)(malloc(sizeof(double)));
    temp2 = (double *)(malloc(sizeof(double)));
    valid1 = (bool *)(malloc(sizeof(bool)));
    valid2 = (bool *)(malloc(sizeof(bool)));
    message1Sent = (bool *)(malloc(sizeof(bool)));
    *message1Sent = false;
}

TempDetector::~TempDetector() {
    free(temp1);
    free(temp2);
    free(valid1);
    free(valid2);
}


void TempDetector::callBack(){
    if (*valid1 && *valid2){
        if ((*temp1 - *temp2) > 1.0 && not *message1Sent){
            messaging->sendMessage1();
            *message1Sent = true;
        }
        if ((*temp1 - *temp2)< 0.5 && *message1Sent){
            *message1Sent = false;
        }
    }


    if (*valid1){
        cout << "detector 1: "<< *temp1 <<endl;
    }
    if (*valid2){
        cout << "detector 2: "<< *temp2 <<endl;
    }
    cout << endl << endl;
}