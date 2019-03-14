#include <iostream>
#include <string>
#include "Shared_ptr.h"

int main()
{
    auto foo = SharedPointer<int>(new int(42));
    auto bar(foo) ;
    cout << *foo << endl;
    cout << foo.use_count() << endl;

    auto string_ptr = SharedPointer<string>(new string("hehe"));
    cout << *string_ptr << endl;
    cout << string_ptr->size() << endl;
    cout << string_ptr.unique() << endl;
    cout << string_ptr.get()->size() <<endl;

    return 0;
}