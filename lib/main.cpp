//-----------------------------------------------------------------------------
//Copyright (c) 2021 Domenico Restuccia
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files (the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in all
//copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//SOFTWARE.
//-----------------------------------------------------------------------------

#include "../include/GPIO/tsic.h"
#include <iostream>
#include <unistd.h>
#include "../include/GUI/mainwindow.h"
#include <iostream>
#include <QApplication>

using namespace std;


void initDetectors(Messaging* messaging, MainWindow* window){
    TempDetector* detectors = new TempDetector(messaging, window);

    cout << "Initializing Detectors"<<endl;

    TSIC* detector1 = new TSIC(detectors->temp1, detectors->valid1, detectors);
    detector1->open(23);
    TSIC* detector2 = new TSIC(detectors->temp2, detectors->valid2, detectors);
    detector2->open(24);
    cout << "Detectors opened"<<endl;
}

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow w;
    cout << "Start"<<endl;
    Messaging* messaging = new Messaging();
    cout << "Initialised Messaging"<<endl;


    initDetectors(messaging, &w);
    messaging->startup();

    w.resize(600,400);
    w.show();
    w.setTemp(0.0,0.0);
    return a.exec();
}
