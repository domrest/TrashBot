//
// Created by domrest on 20/03/2021.
//

#include "tsic.h"
#include <iostream>
#include <unistd.h>

using namespace std;


int main(){
    TempDetector* detectors = new TempDetector();

    cout << "Initializing"<<endl;

    TSIC* detector1 = new TSIC(detectors->temp1, detectors->valid1, detectors);
    detector1->open(14);
    TSIC* detector2 = new TSIC(detectors->temp2, detectors->valid2, detectors);
    detector2->open(15);
    cout << "Detectors opened"<<endl;

    while (1){
        sleep(2);
    }
}