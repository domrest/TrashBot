//
// Created by domrest on 20/03/2021.
//

#include "../include/GPIO/tsic.h"
#include <iostream>
#include <unistd.h>

using namespace std;


void initDetectors(Messaging* messaging){
    TempDetector* detectors = new TempDetector(messaging);

    cout << "Initializing Detectors"<<endl;

    TSIC* detector1 = new TSIC(detectors->temp1, detectors->valid1, detectors);
    detector1->open(23);
    TSIC* detector2 = new TSIC(detectors->temp2, detectors->valid2, detectors);
    detector2->open(25);
    cout << "Detectors opened"<<endl;
}

int main(){
    cout << "Start"<<endl;
    Messaging* messaging = new Messaging();
    cout << "Initialised Messaging"<<endl;

    initDetectors(messaging);
    while(1) {
        sleep(5);
    }

}