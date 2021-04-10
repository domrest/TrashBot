//
// Created by Smithereens101.
//

class INFO{

public: //this is the default, public has to be specified
	string username;
	string password;
	string serverAddress;
	int port;
	string sender;

	//SMTP Messaging::MySMTP;

	string destination;//to
	string subject;	//subject
	string message;	//main body;

};

class Messaging : public INFO,public MySMTP {

public:
	Messaging(string dest, string sbj, string msg);

	// class Car: public Vehicle{} is called inheritance

	/// Destructor
	//~Messaging();
};

/*
int main(int argc, char** argv)
{
	//needs to be called once, don't let multi-threads run it several times
	MyOpenSSL::StaticInitialize sslInitializer;
	MySMTP::SendSSL(
		"smtp.gmail.com", 	//server adress
		465, 			//port
		"discardit101@gmail.com",			//username
		"iybeebgxfnrkgypm",	//app specific password
		"discardit101@gmail.com",//from
		"discardit101@gmail.com",//to
		"Testing Boost SMTP",	//subject
		"But does it djent?"	//main body
	);
	return 0;
}
*/
