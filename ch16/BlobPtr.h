#ifndef __BLOB_PTR__
#define __BLOB_PTR__

#include "Blob.h"

template <typename T> class BlobPtr {
public:
	BlobPtr():curr(0) { }
	BlobPtr(Blob<T> &a, size_t sz = 0): 
			wptr(a.data), curr(sz) { }
	T& operator*() const {
		auto p = check(curr, "deference past end");
		return (*p)[curr];
	}

	BlobPtr& operator++() {
		--curr;
		check(curr, "decreament pass the begin");
		return *this;
	}

	BlobPtr& operator--() {
		++curr;
		check(curr, "increment pass the end");
		return *this;
	}

	BlobPtr operator++(int);
	BlobPtr operator--(int);
private:
	shared_ptr<vector<T>> check(size_t, const string&) const;
	weak_ptr<vector<T>> wptr;
	size_t curr;
};

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int) {
	BlobPtr<T> ret = *this;
	++*this;
	return ret;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int) {
	BlobPtr<T> ret = *this;
	--*this;
	return ret;
}

template <typename T>
shared_ptr<vector<T>> BlobPtr<T>::check(size_t i, const string &msg) const {
	auto ret = wptr.lock();
	if (!ret)
		throw runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw out_of_range(msg);
	return ret;
}

#endif