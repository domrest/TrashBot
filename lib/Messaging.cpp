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
#include "../include/messaging/Socketing.hpp"
#include "../include/messaging/MyOpenSSL.hpp"
#include "../include/messaging/MySMTP.hpp"
#include "../include/messaging/Messaging.h"


Messaging::Messaging()
{
    MyOpenSSL::StaticInitialize sslInitializer;
    info = *new INFO();

    info.username        = "discardit101@gmail.com";
    info.password        = "nackwwuzyfgosaem";
    info.serverAddress   = "smtp.gmail.com";
    info.port            = 465;
    info.sender          = "discardit101@gmail.com";
    info.destination     = "Domenico.Restuccia@glasgow.ac.uk";
    info.subject         = "Trashbot message";
    info.message1        = "Your trash is heating up";
    info.message2        = "Throw out your trash!!!";

}

void Messaging::sendMessage1(){
    MySMTP::SendSSL(
            info.serverAddress, 	//server adress
            info.port, 			//port
            info.username,			//username
            info.password,	//app specific password
            info.sender,//from
            info.destination,//to
            info.subject,	//subject
            info.message1	//main body
    );
    cout << "Message 1 Sent" << endl;
}

void Messaging::sendMessage2(){
    MySMTP::SendSSL(
            info.serverAddress, 	//server adress
            info.port, 			//port
            info.username,			//username
            info.password,	//app specific password
            info.sender,//from
            info.destination,//to
            info.subject,	//subject
            info.message2	//main body
    );
}