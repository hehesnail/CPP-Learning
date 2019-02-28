// !ex13.18, 13.19
#include <iostream>
#include <string>

using namespace std;

class Employee {
public:
	Employee():name("null"), myid(id++) { }
	Employee(const string& na):name(na), myid(id++) { }
	const string& getName() const { return name; }
	const int getID() const { return myid; }
	Employee(const Employee&) = delete;
	Employee& operator= (const Employee&) = delete;

private:
	string name;
	int myid;
	static int id;
};
int Employee::id = 1;

int main() {
	Employee p1;
	Employee p2("Peter");

	cout << p1.getName() << " " << p1.getID() << endl;
	cout << p2.getName() << " " << p2.getID() << endl;

	// !delete function will prevent copy construction
	// Employee p3 = p2;

	return 0;
}
