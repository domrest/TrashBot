
<h1 align="center"> Messaging </h1>

## How the message works

The main functionality of the message functionality was created by following the guide found here: http://raspberrypiprogramming.blogspot.com/2014/09/send-email-to-gmail-in-c-with-boost-and.html


The code relies on 4 Classes for sending the message: ‘MySMTP’, ‘Socket’, ’MyOpenSSL’ and ‘Messaging’. The SMTP class which takes the server address, the port, the sender and the destination and the message subject and body. Socket maintaints the connection using the server address and port information. Since gmail is used the service address is smtp.gmail.com and the port is 465 because Secure Sockets Layer (SSL) is used. SSL is a secure way to read and write data to the connection. 

For simple implementation in the main program a messaging class is created. It defines everything SMTP needs to send a message and creates different messages for when Thrashbot starts up, when the trash is heating up and when the trash has to be taken out.


## Message usage

Currently the message contents and destination are hardcoded and can only be changed in Messaging.cpp.
