#include "Messaging.h"
#include "MyOpenSSL.hpp"

Messaging::Messaging(string _username, string _password) {
    username = _username;
    password = _password;
    MyOpenSSL::StaticInitialize sslInitializer;
}

Messaging::~Messaging(){

}
