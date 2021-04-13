#include <cmath>
#include "../include/GUI/mainwindow.h"


MainWindow::MainWindow(): gain(5), count(0)
{
   // this->setStyleSheet("background-color: white;");

  //  connect( knob, SIGNAL(valueChanged(double)), SLOT(setGain(double)) );

    thermo1 = new QwtThermo;

    thermo1->setPipeWidth(20);
    thermo1->setFillBrush( QBrush(Qt::red) );
    thermo1->show();

    thermo2 = new QwtThermo;
    thermo2->setPipeWidth(20);
    thermo2->setFillBrush( QBrush(Qt::red) );
    thermo2->show();

    label = new QLabel("TrashBot");
    QFont font=label->font();
    font.setPointSize(30);
    font.setBold(true);
    label->setFont(font);
    label->setStyleSheet("border: 2px solid black;");

    QVBoxLayout  *vLayout, *vL1, *vL2;  // vertical layout
        QHBoxLayout  *hLayout;
        vLayout = new QVBoxLayout;

        vLayout->addWidget(label,0, Qt::AlignCenter);

       // vLayout->addWidget(thermo);
        hLayout = new QHBoxLayout;
              vL1= new QVBoxLayout;
              vL1->addWidget(thermo1);
              l1= new QLabel("Thermometer 1");
              QFont f=l1->font();
              f.setPointSize(10);
              f.setBold(true);
              l1->setFont(f);
             // l1->setStyleSheet("border: 1px solid black;");
              vL1->addWidget(l1);
           //   hLayout->addWidget(thermo1);

             vL2 =new QVBoxLayout;
             vL2->addWidget(thermo2);
             l2= new QLabel("Thermometer 2");
             QFont f1=l2->font();
             f1.setPointSize(10);
             f1.setBold(true);
             l2->setFont(f1);
             vL2->addWidget(l2);
             vL2->setContentsMargins(40,0,0,0);
            //  hLayout->addWidget(thermo2);
             l3 = new QLabel("Temp Difference:");
             QFont font2=l3->font();
                   font2.setPointSize(25);
                   font2.setBold(true);
                   l3->setFont(font2);
                   l4= new QLabel();
                   QFont font3=l4->font();
                   font3.setPointSize(25);
                   font3.setBold(true);
                   l4->setFont(font3);

                  //l3->setStyleSheet("border: 1px solid black;");
                //   vL3->addWidget(l3);
                   hLayout->setContentsMargins(70,40,0,20);
                   hLayout->addLayout(vL1);
                   hLayout->addLayout(vL2);
                   hLayout->addWidget(l3);
                   hLayout->addWidget(l4);
                   vLayout->addLayout(hLayout);
                   setLayout(vLayout);
}
void MainWindow::setGain(double gain)
{
    // for example purposes just change the amplitude of the generated input
    this->gain = gain;
}
void MainWindow::setTemp(double temp1,double temp2)
{
    thermo1->setValue(temp1);
    thermo2->setValue(temp2);
    l4->setText(QString::number(temp1-temp2));

}
/*void MainWindow::timerEvent( QTimerEvent * )
{
    double inVal = gain * sin( M_PI * count/50.0 );
    ++count;

    // set the thermometer value
    thermo1->setValue( inVal + 10 );
thermo2->setValue( inVal + 10 );
}*/

/*MainWindow::~MainWindow()
{
}
*/



