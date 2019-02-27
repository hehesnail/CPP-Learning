#include <iostream>

using namespace std;

class Account {
public:
	void calculate() { amount += amount * interestRate; }
	static double rate() { return interestRate; }
	static void rate(double); 

private:
	string owner;
	double amount;
	static double interestRate;
	static double initRate();
};

double Account::initRate() { return 0.05; }
double Account::interestRate = initRate();

void Account::rate(double newRate) {
	interestRate = newRate;
}

int main() {

	double r;
	r = Account::rate();
	cout << r << endl;
	
	Account ac1;
	Account *ac2 = &ac1;
	
	r = ac2->rate();
	cout << r << endl;
	
	r = ac1.rate();
	cout << r << endl;

	return 0;
}