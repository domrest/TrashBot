//-----------------------------------------------------------------------------
//Copyright (c) 2021 Ulvis Silavnieks 
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files (the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in all
//copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//SOFTWARE.
//-----------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <stdint.h>	    //unit16_t
#include <stdexcept>	//runtime exceptions
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
    info.startup         = "Trashbot Starting";

}

void Messaging::startup(){
    MySMTP::SendSSL(
            info.serverAddress, 	//server adress
            info.port, 			    //port
            info.username,			//username
            info.password,	        //app specific password
            info.sender,            //from
            info.destination,       //to
            info.subject,	        //subject
            info.startup	        //main body
    );
    cout << "Startup Sent" << endl;
}

void Messaging::sendMessage1(){
    MySMTP::SendSSL(
            info.serverAddress, 	//server adress
            info.port, 			    //port
            info.username,			//username
            info.password,	        //app specific password
            info.sender,            //from
            info.destination,       //to
            info.subject,	        //subject
            info.message1	        //main body
    );
    cout << "Message 1 Sent" << endl;
}

void Messaging::sendMessage2(){
    MySMTP::SendSSL(
            info.serverAddress, 	
            info.port, 			
            info.username,			
            info.password,	
            info.sender,
            info.destination,
            info.subject,	
            info.message2	
    );
}
