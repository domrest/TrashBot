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
#include "stdafx.h"
#include "Socketing.hpp"
#include "MyOpenSSL.hpp"
#include "MySMTP.hpp"
#include "Messaging.h"

int main(int argc, char** argv)
{
// message(destination, message subject, message content)
Messaging message("discardit101@gmail.com", "Test", "Testing");


	return 0;
}

