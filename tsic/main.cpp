//
// Created by domrest on 20/03/2021.
//

#include "tsic.h"
#include <iostream>


int main(){
    TSIC* detector1 = new TSIC();
    detector1->open(14);

    double detector1Temp= 0.0;

    while (1){
        bool received = detector1->getDegrees(detector1Temp);
        if (received){
            std::cout << detector1Temp;
        }
        _sleep(1);
    }
}