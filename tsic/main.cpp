//
// Created by domrest on 20/03/2021.
//

#include "tsic.h"
#include <iostream>
#include <unistd.h>

using namespace std;

struct TempDetectors {
    double* temp1;
    bool* valid1;
    double* temp2;
    bool* valid2;
};

TempDetectors* createTempDetectors(){
    TempDetectors* detectors = new TempDetectors();
    detectors->temp1 = (double *)(malloc(sizeof(double)));
    detectors->temp2 = (double *)(malloc(sizeof(double)));
    detectors->valid1 = (bool *)(malloc(sizeof(bool)));
    detectors->valid2 = (bool *)(malloc(sizeof(bool)));
    return detectors;
}

void destroyTempDetectors(TempDetectors* detectors){
    free(detectors->temp1);
    free(detectors->temp2);
    free(detectors->valid1);
    free(detectors->valid2);
    free(detectors);
}

int main(){
    TempDetectors* detectors = createTempDetectors();

    cout << "Initializing"<<endl;

    TSIC* detector1 = new TSIC(detectors->temp1, detectors->valid1);
    detector1->open(14);
    TSIC* detector2 = new TSIC(detectors->temp2, detectors->valid2);
    detector2->open(15);
    cout << "Detectors opened"<<endl;

    while (1){
        if (*detectors->valid1){
            cout << "detector 1: "<< *detectors->temp1 <<endl;
        }
        if (*detectors->valid2){
            cout << "detector 2: "<< *detectors->temp2 <<endl;

        }
        cout <<endl <<endl;
        sleep(0.2);
    }
}