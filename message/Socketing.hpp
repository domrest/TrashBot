namespace SocketNS
{
	using boost::asio::ip::tcp; // will be using tcp exclusively so this is convenient

class Socket
{
	//apparently a io_service object has to be declared
	asio::io_service IOService_; 
	tcp::socket socket_;
public: //sth like 'class Misc : public Socket{}' would inherit the public members of Socket
	Socket(string server, uint16_t port)
	: socket_(IOService_)//Creating and connecting to the socket
	{
		//resolving the endpoint this is the IP address and the port (unique host process ID)
		tcp::resolver resolver(IOService_); //tapping into the function
		//the resolver takes a query object and turns it into a list of endpoints as far as
		//I understand this means it looks at some process/es we are requesting and gets the ID
		tcp::resolver::query query(server,to_string(port));
		// returning the list using an iterator - not sure what this means. Perhaps iterating through the 
		//endpoints and generating a list of  some form
		tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
		
		// The list may containg IPv4/6 convention so we need to find the one that works this function
		// does this automatically:
		asio::connect(socket_,endpoint_iterator);
		//at this stage the connection is open and we can read the response
	}
	tcp::socket *GetSocket() {return &socket_;} //so the return is a handle
};
}
