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
#include "stdafx.h"
#include "Socketing.hpp"
#include "MyOpenSSL.hpp"
#include "MySMTP.hpp"

//header files look into it. also linking, that is the likely issue

int main(int argc, char **argv)
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
