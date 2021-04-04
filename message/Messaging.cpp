//
// Created by Smithereens101.
//

#include <iostream>
#include <string>	//string, to_string
#include <stdint.h>	//unit16_t
#include <stdexcept>	//runtime exception
#include <boost/asio.hpp>
#include <boost/archive/iterators/base64_from_binary.hpp>
#include <boost/archive/iterators/transform_width.hpp>
#include <openssl/err.h>
#include <openssl/ssl.h>
using namespace std;
using namespace boost;
#include "Socketing.hpp"
#include "MyOpenSSL.hpp"
#include "MySMTP.hpp"

#include "Messaging.h"

Messaging::Messaging(string dest, string sbj, string msg)
{
	Messaging::INFO info;

	info.username = "discardit101@gmail.com";
	info.password = "";
	info.serverAddress = "smtp.gmail.com";
	info.port = 465;
	info.sender = "discardit101@gmail.com";

	info.destination = dest;
	info.subject = sbj;
	info.message = msg;

	MyOpenSSL::StaticInitialize sslInitializer;
	Messaging::SendSSL(
		info.serverAddress, 	//server adress
		info.port, 			//port
		info.username,			//username
		info.password,	//app specific password
		info.sender,//from
		info.destination,//to
		info.subject,	//subject
		info.message	//main body
	);
}
