#include <iostream>
#include <string>
#include "unique_ptr.h"

int main()
{
    auto string_ptr = unique_pointer<string>(new string("hehe"));
    cout << *string_ptr << endl;
    cout << string_ptr->size() << endl;
    cout << string_ptr.get()->size() <<endl;

    return 0;
}