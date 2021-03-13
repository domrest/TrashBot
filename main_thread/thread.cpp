#include <iostream>
#include <thread>
#include "CppThread.h" //to inherit it in our own class


class mythreadclass : public CppThread
{
private:
	void run()
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
                printf("interrupt!\n");//read
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
	mythreadclass mythreadobject;
	mythreadobject.start(); //inherited func used
	mythreadobject.run(); //you own defined func used



}