#ifndef __MYSTRING__
#define __MYSTRING__

#include <cstring>

class String
{
public:
	String(const char* cstr = 0);
	String(const String&);
	String& operator = (const String&);
	~String();
	char* get_c_str() const {return m_data;}

private:
	char *m_data;
};

inline
String::String(const char* cstr)
{
	if (cstr)
	{
		m_data = new char[strlen(cstr) + 1];
		strcpy(m_data, cstr);
	}
	else
	{
		m_data = new char[1];
		*m_data = '\0';
	}
}

inline 
String::String(const String& s)
{
	m_data = new char[strlen(s.m_data) + 1];
	strcpy(m_data, s.m_data);
}

inline 
String& String::operator = (const String& s)
{
	if (this == &s)
		return *this;
	delete[] m_data;
	m_data = new char[strlen(s.m_data) + 1];
	strcpy(m_data, s.m_data);
}

inline
String::~String()
{
	delete[] m_data;
}

#endif