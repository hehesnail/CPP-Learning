#include <iostream>
#include <memory>
#include <string>

using namespace std;

struct destination {
	string ip;
	int port;
	destination(string ip_, int port_): ip(ip_), port(port_) { }
};

struct connection {
	string ip;
	int port;
	connection(string ip_, int port_): ip(ip_), port(port_) { }
};

connection connect(destination* pDest) {
	shared_ptr<connection> pCon(new connection(pDest->ip, pDest->port));
	cout << "creating connection: " << pCon.use_count() << endl;
	cout << "connect to " << pCon->ip << '-' << pCon->port << endl;
	return *pCon;
}
void disconnect(connection conn) {
	cout << "disconnect: " << conn.ip << '-' << conn.port << endl;
}

void end_connection(connection* p) {disconnect(*p);}

void f(destination &d) {

	connection c = connect(&d);
	//shared_ptr<connection> p(&c, end_connection);
	shared_ptr<connection> p(&c, [] (connection* p) {disconnect(*p);});
	cout << "connecting now: " << p.use_count() << endl;
}

int main() {

	destination d("202.120.32.244", 26422);
	f(d);

	return 0;
}