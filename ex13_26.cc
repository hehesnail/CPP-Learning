#include "ex13_26.h"

//! define begin and end member function
//  define functions here, because we need to know 
//  both StrBlobPtr and StrBlob 
ConstStrBlobPtr StrBlob::begin() {
	return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::end() {
	auto ret = ConstStrBlobPtr(*this, data->size());
	return ret;
}

int main() {

	return 0;
}