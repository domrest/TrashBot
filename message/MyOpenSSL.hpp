//
// Created by Jay http://raspberrypiprogramming.blogspot.com/2014/09/send-email-to-gmail-in-c-with-boost-and.html.
//

class MyOpenSSL
{
	unique_ptr< SSL_CTX, decltype(SSL_CTX_free)*>ctx_;//SSL_CTX is an object holding data for TLS/SSL/DTLS session
	unique_ptr<SSL, decltype(SSL_free)*>ssl_;
	enum{errorBufSize = 256, readBufSize = 256};
public:
//Methods can be: SSLv2_method, SSLv3_method, TLSv1_method, SSLv23_method


	MyOpenSSL(int socket, const SSL_METHOD *method = SSLv23_method() )
		: ctx_(nullptr, SSL_CTX_free)
		, ssl_(nullptr, SSL_free)
	{
		char errorBuf[errorBufSize];
		// then Enabling SSL_CTX object as a framework to establish TLS/SSL enabled connection
		ctx_ = decltype(ctx_)(SSL_CTX_new(method),SSL_CTX_free);
		if (nullptr == ctx_) throw runtime_error(ERR_error_string(ERR_get_error(), errorBuf));

		//SSL struct to hold data for the connection
		ssl_ = decltype(ssl_)(SSL_new(ctx_.get()), SSL_free);
		if (nullptr == ssl_) throw runtime_error( ERR_error_string(ERR_get_error(),errorBuf));
		
		// When a network connection has been created it can be assigned to an SSL object
		// After the SSL object has been created using SSL_new
		//SSL_set_fd or SSL_set_bio can be used to associate the network connection with the object
		const int rstSetFd = SSL_set_fd(ssl_.get(), socket);
		if (0==rstSetFd) throw runtime_error( ERR_error_string(ERR_get_error(),errorBuf));

		// performing TLS/SSL handshake using SSL_accept or SSL_connect respectively
		const int rstConnect = SSL_connect(ssl_.get());
		if (0 == rstConnect) throw runtime_error("handshake failed.");
		else if (0 > rstConnect) throw runtime_error("handshake and shutdown failed.");
	}

	void Write(const string &msg)
	{
		//SSL_read and SSL_write are used to read and write data on the TLS/SSL connection
		const int rstWrite = SSL_write(ssl_.get(), msg.c_str(), msg.length());
		if (0 == rstWrite) throw runtime_error("socket write failed due to loss of connection");
		else if (0>rstWrite) throw runtime_error("socket write failed due to unknown reason");
	}
	template < typename IsDoneReceivingFunctorType > string Read(IsDoneReceivingFunctorType isDoneReceiving)
	{
		char buf[readBufSize];
		string read;
		while (true)
		{
			const int rstRead = SSL_read(ssl_.get(),buf,readBufSize);
			if (0 == rstRead) throw runtime_error("Connection lost while read");
			if (0 > rstRead && SSL_ERROR_WANT_READ == SSL_get_error(ssl_.get(), rstRead)) continue;
			read += string(buf, buf + rstRead);
			if (isDoneReceiving( read )) return read;
		}
	}

	~MyOpenSSL() noexcept(false)
	{
		//SSL_shutdown can be used to shut down the TLS/SSL connection
		int rstShutdown = SSL_shutdown(ssl_.get());
		if (0 == rstShutdown) rstShutdown = SSL_shutdown( ssl_.get() );
		else if (-1 == rstShutdown && SSL_RECEIVED_SHUTDOWN != SSL_get_shutdown(ssl_.get()))
		
		throw runtime_error("shutdown failed");
		
	}

	struct StaticInitialize
	{
		StaticInitialize()
		{
			// the library must be initialized first
			ERR_load_crypto_strings();
			SSL_load_error_strings();
			SSL_library_init();
		}
		~StaticInitialize()
		{
			ERR_free_strings();
		}
	};
};
