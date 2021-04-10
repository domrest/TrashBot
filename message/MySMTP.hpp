//
// Created by Jay http://raspberrypiprogramming.blogspot.com/2014/09/send-email-to-gmail-in-c-with-boost-and.html.
//

class MySMTP //detecting if all messages have meen transferred
{
public:
	static void SendSSL(const string &server, uint16_t port, const string &userName, const string &password, const string &from, const string &to, const string &subject, const string &message )
	{
		//cout << "TEST cout";
		static const string newline = "\r\n";
		SocketNS::Socket socket(server,port);
		MyOpenSSL openSSL(socket.GetSocket() ->native_handle());

		//https://en.wikipedia.org/wiki/Simple_Mail_Transfer_Protocol#SMTP_transport_example
		std::cout << openSSL.Read(ReceiveFunctor(220)) << endl; // 220 mx.google.com ESMTP
		openSSL.Write(string("EHLO ")+server+newline);

		cout << openSSL.Read(ReceiveFunctor(250)); // 250-mx.google.com 
		openSSL.Write(string("AUTH LOGIN") + newline);

		cout << openSSL.Read(ReceiveFunctor(334)); // 334
		openSSL.Write(EncodeBase64(userName) + newline);

		cout << openSSL.Read(ReceiveFunctor(334)); // 334
		openSSL.Write(EncodeBase64(password) + newline);
		
		cout << openSSL.Read(ReceiveFunctor(235)); 
		openSSL.Write(string("MAIL FROM:<") + to + ">" + newline);

		cout << openSSL.Read(ReceiveFunctor(250));
		openSSL.Write(string("RCPT TO:<") + to + ">" + newline);

		cout << openSSL.Read(ReceiveFunctor(250));
		openSSL.Write(string("DATA") + newline);

		cout << openSSL.Read(ReceiveFunctor(354)); //354 go ahead
		openSSL.Write(string("From: <") + from + ">" + newline);
		openSSL.Write(string("To: <") + to + ">" +newline);
		openSSL.Write(string("Subject: ") + subject + newline);
		openSSL.Write(newline + message + newline + "." + newline);
		
		cout << openSSL.Read(ReceiveFunctor(250)) << endl;
		openSSL.Write(string("QUIT") + newline);
		cout << openSSL.Read(ReceiveFunctor(221));
	}

private:
	struct ReceiveFunctor
	{
		enum {codeLength = 3}; //not naming the type?? this is a thing within a class apparently 
					//access by : class::codeLength
		const string code;

		ReceiveFunctor(int expectingCode) : code(to_string(expectingCode))
		{ if (code.length() != codeLength) throw runtime_error("SMTP code must be 3 digits."); }

		//true if msg contains expected 3dig code and there is a newline character folloing
		//false if msg has no newline char -> need to receive more
		//throw if msg doesn't contain the expected code.
		bool operator() (const string &msg) const
		{
			if (msg.length()<codeLength) return false;
			if (code != msg.substr(0,codeLength)) throw runtime_error("SMTP code not received.");

			const size_t posNewline = msg.find_first_of("\n", codeLength);
			if (posNewline == string::npos) return false;
			if (msg.at(codeLength) == ' ') return true; 
			if (msg.at(codeLength) == '-') return this->operator()(msg.substr(posNewline + 1));
			throw runtime_error("Unexpected return code");
		}
	};
	static string EncodeBase64(const string &data)
	{
		typedef archive::iterators::base64_from_binary< // convert binary to base 64
		archive::iterators::transform_width< const char *, 6, 8 > //get 6bit from 8bit
		> Base64;
		return string(Base64(data.c_str()), Base64(data.c_str() + data.length()) );
	}
};
