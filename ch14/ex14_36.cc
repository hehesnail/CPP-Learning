#include <iostream>
#include <string>

using namespace std;

class GetInput{
public:
	GetInput(istream &i = cin): is(i) { }
	string operator()() const {
		string str;
		getline(is, str);
		return is ? str : string();
	} 
private:
	istream &is;
};

int main() {
	GetInput getin(cin);
	cout << getin() << endl;

	return 0;
}