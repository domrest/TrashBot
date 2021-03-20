//
// Created by domrest on 20/03/2021.
//

#include "tsic.h"
#include <iostream>
#include <unistd.h>

using namespace std;


int main(){
    cout << "Initializing";

    TSIC* detector1 = new TSIC();
    detector1->open(14);
    cout << "Detector opened";

    double detector1Temp= 0.0;

    while (1){
        cout << "1 Sec passed";

        bool received = detector1->getDegrees(detector1Temp);
        if (received){
            cout << detector1Temp;
        } else {
            cout << "Still invalid";
        }
        sleep(1);
    }
}