
class Messaging {
public:
    //Constructor
    Messaging(string _username, string _password);

    //Destructor
    ~Messaging();

    void sendEmail(string subject, string message);

private:
    String username;
    String password;
    String serverAddress = "smtp.gmail.com";
    int port = 465;
    String receivingAddress = "discardit101@gmail.com";
};


