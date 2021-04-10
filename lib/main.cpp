//
// Created by domrest on 20/03/2021.
//

#include "../include/GPIO/tsic.h"
#include <iostream>
#include <unistd.h>

using namespace std;


void initDetectors(Messaging* messaging){
    TempDetector* detectors = new TempDetector(messaging);

    cout << "Initializing"<<endl;

    TSIC* detector1 = new TSIC(detectors->temp1, detectors->valid1, detectors);
    detector1->open(14);
    TSIC* detector2 = new TSIC(detectors->temp2, detectors->valid2, detectors);
    detector2->open(15);
    cout << "Detectors opened"<<endl;
}

int main(){

    Messaging* messaging = new Messaging();




}