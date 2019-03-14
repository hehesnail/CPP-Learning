#ifndef __UNIQUE_POINTER__
#define __UNIQUE_POINTER__

#include "Delete.h"

using namespace std;

template <typename, typename>
class unique_pointer;

template <typename T, typename D>
void swap(unique_pointer<T,D> &lhs, unique_pointer<T,D> &rhs) {
	using std::swap;
	swap(lhs.ptr, rhs.ptr);
	swap(lhs.deleter, rhs.deleter);
}

template<typename T, typename D=Delete>
class unique_pointer {
public:

	//prevenet copy ctor and copy assignment
	unique_pointer(const unique_pointer&) = delete;
	unique_pointer& operator=(const unique_pointer&) = delete;

	unique_pointer() = default;
	explicit unique_pointer(T *up): ptr(up) { }

	//move ctor
	unique_pointer(unique_pointer &&up) noexcept : ptr(up.ptr) {
		up.ptr = nullptr;
	}

	//move assignment
	unique_pointer& operator=(unique_pointer &&rhs) noexcept;
	unique_pointer& operator=(std::nullptr_t n) noexcept;

	T& operator*() const {
		return *ptr;
	}

	T* operator->() const {
		return & this->operator*();
	}

	operator bool() const {
		return ptr ? true : false;
	}

	T* get() const {
		return ptr;
	}

	void swap(unique_pointer &rhs) {
		swap(*this, rhs);
	}

	void reset() {
		deleter(ptr);
		ptr = nullptr;
	}

	void reset(T* p) {
		deleter(ptr);
		ptr = p;
	}

	T* release();

	~unique_pointer() {
		deleter(ptr);
	}

private:
	T* ptr;
	D deleter = D();
};

template <typename T, typename D>
inline unique_pointer<T, D>&
unique_pointer<T,D>::operator=(unique_pointer<T,D> &&rhs) noexcept {
	if (this->ptr != rhs.ptr) {
		deleter(ptr);
		ptr = nullptr;
		swap(*this, rhs);
	}

	return *this;
}

template <typename T, typename D>
inline unique_pointer<T, D>&
unique_pointer<T,D>::operator=(std::nullptr_t n) noexcept {
	if (n == nullptr) {
		deleter(ptr);
		ptr = nullptr;
	}

	return *this;
}

template <typename T, typename D>
inline T*
unique_pointer<T,D>::release() {
	T* ret = ptr;
	ptr = nullptr;
	return ret;
}

#endif