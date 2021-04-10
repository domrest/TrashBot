
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <qwt/qwt_thermo.h>
#include <QMainWindow>
#include <QBoxLayout>
#include <QLabel>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();
   // ~MainWindow();
    //void timerEvent( QTimerEvent * );
        double gain;
        int count;
        QLabel *label, *l1, *l2, *l3, *l4;
        QwtThermo    *thermo1, *thermo2;

        void setTemp(double temp1,double temp2);
public slots:
    void setGain(double gain);
};
#endif // MAINWINDOW_H
