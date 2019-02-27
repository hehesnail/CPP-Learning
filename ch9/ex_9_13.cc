#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {

    list<int> a = {1,2,3,4,5};
    vector<double> b(a.begin(), a.end());

    vector<int> c = {1,2,3,4,5};
    vector<double> d(c.begin(), c.end()); 

    return 0;
}