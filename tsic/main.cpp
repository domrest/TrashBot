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
    cout << "Detector opened"<<endl;

    double detector1Temp= 0.0;

    while (1){
        cout << "1 Sec passed"<<endl;

        bool received = detector1->getDegrees(detector1Temp);
        if (received){
            cout << "detector 1: "<< detector1Temp <<endl;
        } else {
            cout << "Still invalid" <<endl;
        }
        sleep(1);
    }
}