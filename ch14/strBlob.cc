#include "strBlob.h"

//! define begin and end member function
//  define functions here, because we need to know 
//  both StrBlobPtr and StrBlob 
StrBlobPtr StrBlob::begin() {
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() {
	auto ret = StrBlobPtr(*this, data->size());
	return ret;
}