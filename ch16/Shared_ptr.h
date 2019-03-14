#ifndef __SHARED_PTR__
#define __SHARED_PTR__

#include <functional>
#include "Delete.h"

using namespace std;

template <typename T>
class SharedPointer;

template <typename T>
void swap(SharedPointer<T> &lhs,  SharedPointer<T> &rhs) {
	using std::swap;
	swap(lhs.ptr, rhs.ptr);
	swap(lhs.ref_count, rhs.ref_count);
	swap(lhs.deleter, rhs.deleter);
}

template <typename T>
class SharedPointer {
	friend void swap<T> (SharedPointer<T>&, SharedPointer<T>&);
public:
	SharedPointer():
		ptr(nullptr), ref_count(new size_t(1)), deleter(Delete()) { }
	
	explicit SharedPointer(T* raw_ptr):
		ptr(raw_ptr), ref_count(new size_t(1)), deleter(Delete()) { }
	
	//copy ctor
	SharedPointer(SharedPointer& rhs):
		ptr(rhs.ptr), ref_count(rhs.ref_count), deleter(rhs.deleter) { 
		++*ref_count;
	}

	//move ctor
	SharedPointer(SharedPointer &&rhs) noexcept :
		ptr(rhs.ptr), ref_count(rhs.ref_count), deleter(std::move(rhs.deleter)) { 
		rhs.ptr = nullptr;
		rhs.ref_count = nullptr;
	}

	//copy assignment
	SharedPointer& operator=(SharedPointer& rhs) {
		++*rhs.ref_count;
		decrement_and_destropy();
		ptr = rhs.ptr, ref_count=rhs.ref_count, deleter = rhs.deleter;
		return *this;
	}

	//move assignment
	SharedPointer& operator=(SharedPointer &&rhs) noexcept {
		swap(*this, rhs);
		rhs.decrement_and_destropy();
		return *this;
	}

	operator bool() const {
		return ptr ? true :false;
	}

	T& operator*() const{
		return *ptr;
	}
	T* operator->() const {
		return & this->operator*();
	}

	size_t use_count() const {
		return *ref_count;
	}

	T* get() const {
		return ptr;
	}

	bool unique() const {
		return *ref_count == 1;
	}

	void swap(SharedPointer &rhs) {
		swap(*this, rhs);
	}

	void reset() {
		decrement_and_destropy();
	}

	void reset(T* p) {
		if (ptr != p) {
			decrement_and_destropy();
			ptr = p;
			ref_count = new size_t(1);
		}
	}

	void reset(T*p, const function<void(T*)> &d) {
		reset(p);
		deleter = d;
	}

	~SharedPointer() {
		decrement_and_destropy();
	}

private:
	T* ptr;
	size_t* ref_count;
	function<void(T*)> deleter;
	void decrement_and_destropy() {
		if (ptr && 0 == --*ref_count) {
			delete ref_count;
			deleter(ptr);
		} else if (!ptr) {
			delete ref_count;
		}

		ref_count = nullptr;
		ptr = nullptr;
	}
};

#endif