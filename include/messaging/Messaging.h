//
// Created by Smithereens101.
//
#include <string>

class INFO{

public: //this is the default, public has to be specified

	std::string username;
    std::string password;
    std::string serverAddress;
	int port;
    std::string sender;

	//SMTP Messaging::MySMTP;

    std::string destination; //to
    std::string subject;	    //subject
    std::string message1;	//main body;
    std::string message2;


};

class Messaging {

public:
	Messaging();
	// class Car: public Vehicle{} is called inheritance

	/// Destructor
	//~Messaging();

	INFO info;

    void sendMessage1();
    void sendMessage2();
};
