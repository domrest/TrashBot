CC=g++
CFLAGS=-g -Wall #-std=c++0x  #-Wall enables all warning c++(num)x is the standard

all: sendmail

sendmail: *.hpp sendmail.cpp
	$(CC) $(CFLAGS) -o sendmail -lcrypto -lboost_iostreams -lboost_filesystem -lpthread -lboost_thread -lboost_system -lssl sendmail.cpp

srdafx.h.gch: stdafx.h
	$(CC) $(CFLAGS) -c stdafx.h
clean:

