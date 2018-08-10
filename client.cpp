#include <iostream>
#include <boost/asio.hpp> //libws2_32.a, libboost_system.a
// #include <windows.h>

using namespace std;
using namespace boost::asio;



class MyClient{
	
	string address = "127.0.0.1";
	int port = 9090;
	
	io_service io;
	
	ip::tcp::socket sock;
	ip::tcp::endpoint endPoint;

	boost::system::error_code err;
	
public:
	MyClient():
		sock(io),
		endPoint(ip::address::from_string(address), port)
	{}

	~MyClient(){
		sock.close();
	}
	
	void connect(){
		sock.connect(endPoint, err);
		
		if(err) 
			throw boost::system::system_error(err);
		else cout << "Connection established" << endl; //Соединение установлено
	}
	
	void go(){
		boost::asio::streambuf sbuf; /*Обязательно должно быть указано
        пространство имени boost::asio, т.к. в std тоже есть streambuf*/
        read_until(sock, sbuf, "!");
        cout << &sbuf << endl;
	}
};

int main(){
    std::cout<<"Client is running!!\n";
	try{
		MyClient myClient;
		myClient.connect();
		myClient.go();
		
    }
    catch(std::exception& e){
        // char buf[512];
        // CharToOem(e.what(), buf); // windows
        // std::cout << "Exception was occured: " << buf << std::endl;

        cout << "Exception has occurred: " << e.what() << endl;/*Произошло
        исключение e*/
    }

	// return 0;
}