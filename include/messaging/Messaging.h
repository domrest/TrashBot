//
// Created by Smithereens101.
//
#include <string>

class INFO{

public:

	std::string username		;
    	std::string password		;
    	std::string serverAddress	;
	int port 			;
    	std::string sender 		;

    	std::string destination		; //to
    	std::string subject		; //subject
    	std::string message1		; //main body
    	std::string message2		;
    	std::string startup		;

};

class Messaging {
public:
	Messaging();
	INFO info;

	void startup();
    	void sendMessage1();
    	void sendMessage2();

};
