#ifndef __TESTSTRING__
#define __TESTSTRING__

#include <cstring>
#include <memory>
#include <utility>

using namespace std;

class String {
public:
	String(): first(nullptr), last(nullptr) { }
	String(const char*);
	String(const String&);
	String& operator=(const String&);
	~String();

	size_t size() const { return last - first; }
	size_t length() const { return last - first - 1; }
	bool empty() const { return first == last; }
	char* begin() const { return first; }
	char* end() const { return last; }
	void print() {
		for (auto i = first; i != last; i++)
			cout << *i;
		cout << endl;
	}

private:
	static allocator<char> alloc;
	char *first;
	char *last;
	pair<char*, char*> alloc_n_copy(const char*, const char*);
	void free();
};

allocator<char> String::alloc;

inline pair<char*, char*> 
String::alloc_n_copy(const char *b, const char *e) {
	auto data = alloc.allocate(e - b);
	return {data, uninitialized_copy(b, e, data)};
}

inline
void String::free() {
	for (auto p = last; p != first;) {
		alloc.destroy(--p);
	}
	alloc.deallocate(first, last - first);
}

inline 
String::String(const char *s) {
	if (s) {
		size_t n = strlen(s) + 1;
		auto data = alloc_n_copy(s, s+n);
		first = data.first;
		last = data.second;
	} 
	else {
		first = alloc.allocate(1);
		alloc.construct(first, '\0');
		last = first + 1;
	}
}

inline 
String::String(const String &s) {
	auto data = alloc_n_copy(s.begin(), s.end());
	first = data.first;
	last = data.second;
	cout << "string copy constructor" << endl;
}

inline 
String& String::operator=(const String &s) {
	auto data = alloc_n_copy(s.begin(), s.end());
	free();
	first = data.first;
	last = data.second;
	cout << "string copy operator =" << endl;
}

inline 
String::~String() {
	free();
}

#endif 