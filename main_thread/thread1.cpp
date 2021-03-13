#include <iostream>
#include <thread>
#include "CppThread.h" //to inherit it in our own class


class mythreadclass : public CppThread
{
private:
	void run(/*should this be modified? *//*  int *arr_1, int *arr_2   */)
	{
        while(1) { //while loop it while(1) 
            
            fflush(stdout);

            // wait for a falling edge at the pin gpio
            rc = gpio_poll(gpio_fd, POLL_TIMEOUT);

            // standard linux error codes in case of failure
            if (rc < 0) {
                printf("\npoll() failed!\n");
                return -1;
            }

            // success. An interrupt has occurred.
            if (rc > 0) {
                printf("interrupt!\n");//read into pointer buffer
                //bufferpointer = incoming value
                /* arr_1[]=
                *  arr_2[]=
                */
            }

            // timeout, poll returned after a timeout
            if (rc == 0) {
                printf("timeout\n");
            }

            fflush(stdout);
        }
	}
}
}

int main()
{ 
    //defined variables initializations
    int threshold // define it

    /* *initializations for input pins to get sensor_1 and sensor_2 values
    * 
    * 
    * 
       *define a pointer to a buffer_1 and pointer to buffer_2 */
        //int buffer_1[];
        //int buffer_2[];

	mythreadclass mythreadobject;
	mythreadobject.start(); //inherited func used
	mythreadobject.run(/*pass in the two above defined  pointers as *//* buffer_1, buffer_2 */); //your own defined func used inside run
    /* 
        *Is buffer_1 and buffer_2 readable and understable as a temperature?
        *If so, Compare buffer_1 with buffer_2 and get a value
       
        *if (value > threshold) // compare that value with threshold
            { 
                     //send an alert to user    
            }
    */


}