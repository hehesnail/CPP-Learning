#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <initializer_list>
#include <stdexcept>

using namespace std;

class StrBlobPtr;

/**
 * @brief the StrBlob class for ex12.2
 */
class StrBlob {
public:
	friend class StrBlobPtr;
	typedef vector<string>::size_type size_type;

	/**
	 * @brief constructors
	 */
	StrBlob();
	StrBlob(initializer_list<string> il);

	/**
	 * @brief member functions
	 */
	size_type size () const {return data->size();}
	bool empty() const {return data->empty();}

	//! add and remove
	void push_back(const string& t) {data->push_back(t);}
	void pop_back();

	//! elements access
	string& front();
	string& back();
	const string& front() const;
	const string& back() const;

private:
	shared_ptr<vector<string>> data;
	//! throw msg if data[i] isn't valid
	void check(size_type i, const string& msg) const;
};

/**
 * @brief default costructor
 */
StrBlob::StrBlob(): data(make_shared<vector<string>>() ) { }

/**
 * @brief constrcutor
 * @param il initializer_list to construct the data
 */
StrBlob::StrBlob(initializer_list<string> il):
				data(make_shared<vector<string>>(il) ) { }

/**
 * @brief utility function to check if data[i] is valid
 * @param i index
 * @param msg message to throw out
 */
void StrBlob::check(size_type i, const string& msg) const {
	if (i >= data->size())
		throw out_of_range(msg);
}

/**
 * @brief remove the last element
 */
void StrBlob::pop_back() {
	check(0, "pop_back on empty blob");
	data->pop_back();
}

/**
 * @brief get the first element
 * @return write/read reference to first element
 */
string& StrBlob::front() {
	check(0, "front on empty blob");
	return data->front();
}

/**
 * @brief get the last element
 * @return write/read reference to last element
 */
string& StrBlob::back() {
	check(0, "back on empty blob");
	return data->back();
}

/**
 * @brief get the first element
 * @return const reference to first element
 */
const string& StrBlob::front() const {
	check(0, "front on empty blob");
	return data->front();
}

/**
 * @brief get the last element
 * @return const reference to the last element
 */
const string& StrBlob::back() const {
	check(0, "back on empty blob");
	return data->back();
}

/**
 * @brief StrBlobPtr class for ex 12.19
 *  binds to corresponding StrBlob class
 */
class StrBlobPtr {
public:
	/**
	 * @brief constructors
	 */
	StrBlobPtr(): curr(0) { }
	StrBlobPtr(StrBlob &a, size_t sz = 0):
			wptr(a.data), curr(sz) { }

    /**
     * @brief member functions
     */
	string& deref() const;
	StrBlobPtr& incr();

private:
	//! throw msg if index causes exception
	shared_ptr<vector<string>> check(size_t, const string&) const;
	weak_ptr<vector<string>> wptr;
	size_t curr = 0;
};

/**
 * @brief utility function to check if i or wptr is valid
 * @param i index
 * @param msg message to throw if i out of range
 * @return valid share_ptr pointer
 */
shared_ptr<vector<string>>
StrBlobPtr::check(size_t i, const string& msg) const {
	auto ret = wptr.lock();
	if (!ret)
		throw runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw out_of_range(msg);
	return ret;
}

/**
 * @brief dereference
 * @return string reference to data[curr]
 */
string&
StrBlobPtr::deref() const {
	auto p = check(curr, "dereference pass the end");
	return (*p)[curr];
}

/**
 * @brief increment curr if valid
 * @return reference to StrBlobPtr after curr changed
 */
StrBlobPtr&
StrBlobPtr::incr() {
	auto p = check(curr, "increment pass end of StrBlobPtr");
	curr++;
	return *this;
}

int main() {

	StrBlob b1;
	{
		StrBlob b2 = {"a", "an", "the"};
		b1 = b2;
		b2.push_back("about");
		cout << "b2 size " << b2.size() <<endl;
	}
	cout << "b1 size " << b1.size() << endl;

	//const StrBlob b3 = {"a", "b", "c"};
	//b3.push_back("d");
	//cout << "b3 size " << b3.size() << endl;

	return 0;
}