#ifndef __BLOB__
#define __BLOB__

#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

using namespace std;

template <typename> class BlobPtr;
template <typename> class Blob;
template <typename T> 
bool operator==(const Blob<T>&, const Blob<T>&);

template <typename T> class Blob {
	friend class BlobPtr<T>;
	friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
public:
	typedef T value_type;
	typedef typename vector<T>::size_type size_type;
	Blob();
	Blob(initializer_list<T> il);
	template <typename It> Blob(It, It);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const T &t) { data->push_back(t); }
	void push_back(const T &&t) { data->push_back(std::move(t)); }
	void pop_back();
	T& back();
	T& operator[] (size_type i);
private:
	shared_ptr<vector<T>> data;
	void check(size_type i, const string &msg) const;
};

template <typename T>
Blob<T>::Blob(): data(make_shared<vector<T>>()) { }

template <typename T>
Blob<T>::Blob(initializer_list<T> il): data(make_shared<vector<T>>(il)) { }

template <typename T>
template <typename It>
Blob<T>::Blob(It l1, It l2): data(make_shared<vector<T>>(l1, l2)) { }

template <typename T>
void Blob<T>::check(size_type i, const string &msg) const {
	if (i >= data->size())
		throw out_of_range(msg);
}

template <typename T>
T& Blob<T>::back() {
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T>
T& Blob<T>::operator[](size_type i) {
	check(i, "subscirpt out of range");
	return (*data)[i];
}

template <typename T>
void Blob<T>::pop_back() {
	check(0, "pop back on empty Blob");
	data->pop_back();
}

template <typename T>
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs) {
	return (lhs.curr == rhs.curr);
}

#endif