#ifndef __STRVEC__
#define __STRVEC__

#include <string>
#include <memory>
#include <utility>
#include <initializer_list>

using namespace std;

class StrVec {
public:
	StrVec():elements(nullptr), first_free(nullptr), cap(nullptr) { }
	StrVec(const StrVec&);
	StrVec(StrVec &&) noexcept;
	StrVec(initializer_list<string>);
	StrVec& operator=(const StrVec&);
	StrVec& operator=(StrVec &&) noexcept;
	~StrVec();

	void push_back(const string&);
	void push_back(string &&);
	size_t size() const {return first_free - elements; }
	size_t capacity() const {return cap - elements; }
	string *begin() const { return elements; }
	string *end() const { return first_free; }

	void reserve(size_t newcap);
	void resize(size_t cnt);
	void resize(size_t cnt, const string&);

private:
	static std::allocator<string> alloc;
	void chk_n_alloc() {
		if (size() == capacity())
			reallocate();
	}
	pair<string*, string*> alloc_n_copy 
		(const string*, const string*);
	void alloc_n_move(size_t newcap);
	void free();
	void reallocate();
	string *elements;
	string *first_free;
	string *cap; 
};

allocator<string> StrVec::alloc;

inline 
void StrVec::push_back(const string &s) {
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

inline
void StrVec::push_back(string &&s) {
	chk_n_alloc();
	alloc.construct(first_free++, std::move(s));
}

inline pair<string*, string*>
StrVec::alloc_n_copy(const string *b, const string *e) {
	auto data = alloc.allocate(e - b);
	return {data, uninitialized_copy(b, e, data)};
}

inline
void StrVec::free() {
	if (elements) {
		for (auto p = first_free; p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
	//for_each(elements, first_free, [this](std::string &s){ alloc.destroy(&s); });
}

inline 
StrVec::StrVec(const StrVec &s) {
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free, cap = newdata.second;
}

inline
StrVec::StrVec(StrVec &&s) noexcept
	:elements(s.elements), first_free(s.first_free), cap(s.cap) {
	s.elements = s.first_free = s.cap = nullptr;
}

inline
StrVec::StrVec(initializer_list<string> ll) {
	auto newdata = alloc_n_copy(ll.begin(), ll.end());
	elements = newdata.first;
	first_free, cap = newdata.second;
}

inline 
StrVec::~StrVec() {
	free();
}

inline 
StrVec& StrVec::operator=(const StrVec &s) {
	auto data = alloc_n_copy(s.begin(), s.end());
	free();
	elements = data.first;
	first_free = data.second;

	return *this;
}

inline
StrVec& StrVec::operator=(StrVec &&rhs) noexcept {
	if (this != &rhs) {
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}

	return *this;
}

inline
void StrVec::alloc_n_move(size_t newcap) {
	auto newdata = alloc.allocate(newcap);
	auto dest = newdata;
	auto elem = elements;

	for (size_t i = 0; i != size(); i++)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcap;
}

inline 
void StrVec::reallocate() {
	auto newcapacity = size() ? size()*2 : 1;
	alloc_n_move(newcapacity);
	/*
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;

	for (size_t i = 0; i != size(); i++) {
		alloc.construct(dest++, std::move(*elem++));
	}

	free();

	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
	*/
}

inline 
void StrVec::reserve(size_t newcap) {
	if (newcap <= capacity()) return;
	alloc_n_move(newcap);
}

inline 
void StrVec::resize(size_t cnt) {
	resize(cnt, string());
}

inline 
void StrVec::resize(size_t cnt, const string &s) {
	if (cnt > size()) {
		if (cnt > capacity())
			reserve(2*cnt);
		for (size_t i = size(); i != cnt; i++)
			alloc.construct(first_free++, s);
	}
	else if (cnt < size()) {
		while (first_free != elements + cnt) {
			alloc.destroy(--first_free);
		}
	}
}

#endif