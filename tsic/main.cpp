//
// Created by domrest on 20/03/2021.
//

#include "tsic.h"
#include <iostream>
#include <unistd.h>

using namespace std;


int main(){
    cout << "Initializing"<<endl;

    TSIC* detector1 = new TSIC();
    detector1->open(14);
    TSIC* detector2 = new TSIC();
    detector2->open(15);
    cout << "Detectors opened"<<endl;

    double detector1Temp= 0.0;
    double detector2Temp= 0.0;


    while (1){
        cout << "1 Sec passed"<<endl;

        bool received1 = detector1->getDegrees(detector1Temp);
        bool received2 = detector2->getDegrees(detector2Temp);

        if (received1){
            cout << "detector 1: "<< detector1Temp <<endl;
        }
        if (received2){
            cout << "detector 2: "<< detector2Temp <<endl;

        }
        sleep(1);
    }
}