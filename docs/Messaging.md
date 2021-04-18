

<h1 align="center"> Messaging </h1>

## How the message works

The main functionality of the message functionality was created by following the guide found here: http://raspberrypiprogramming.blogspot.com/2014/09/send-email-to-gmail-in-c-with-boost-and.html


The code relies on 4 Classes for sending the message: ‘MySMTP’, ‘Socket’, ’MyOpenSSL’ and ‘Messaging’. The SMTP class which takes the server address, the port, the sender and the destination and the message subject and body. Socket maintaints the connection using the server address and port information. Trashbot communicates with smtp.gmail.com using port 465 to read and write data to the connection using Secure Sockets Layer (SSL). 

For simple implementation in the main program a messaging class is created. It defines everything SMTP needs to send a message and creates different messages for when Thrashbot starts up, when the trash is heating up and when the trash has to be taken out.


## Message usage

Currently the message contents and destination are hardcoded and can only be changed in Messaging.cpp.

## A short demo


https://user-images.githubusercontent.com/77978118/115160562-c376a700-a090-11eb-993b-aa074892db83.mp4




