#include <iostream>
#include <vector>
#include <memory>

using namespace std;

/**
 * pointer to vector<int> normal version
 * Using new/delete to manage memory
 */
vector<int>* vecGen() {

	return new vector<int>();
}

istream& input(istream& in, vector<int>* v) {
	int a, b, c, d;
	in >> a >> b >> c >> d;
	v->push_back(a);
	v->push_back(b);
	v->push_back(c);
	v->push_back(d);

	return in;
}

ostream& output(ostream& out, vector<int>* v) {
	vector<int>::size_type len = v->size();
	for (int i = 0; i != len; i++)
		out << (*v)[i] << " ";
	delete v;
	return out;
}


/**
 * pointer to vector<int> smart pointer version
 * user shared_ptr to manage memory
 */
shared_ptr<vector<int>> vecGenS() {

	return make_shared<vector<int>> ();
}

istream& input(istream& in, shared_ptr<vector<int>> v) {
	int a, b, c, d;
	in >> a >> b >> c >> d;
	v->push_back(a);
	v->push_back(b);
	v->push_back(c);
	v->push_back(d);

	return in;
}

ostream& output(ostream& out, shared_ptr<vector<int>> v) {
	vector<int>::size_type len = v->size();
	for (int i = 0; i != len; i++)
		out << (*v)[i] << " ";
	//delete v;
	return out;
}


bool b() {
	int *p = new int;
	return p;
}

int main() {

	vector<int>* v = vecGen();
	input(cin, v);
	output(cout, v);
	cout << endl;

	shared_ptr<vector<int>> vs = vecGenS();
	input(cin, vs);
	output(cout, vs);
	cout << endl;

	bool f = b();
	cout << f << endl;

	return 0;
}