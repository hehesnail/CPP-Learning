#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>

#include "textquery.h"
#include "query.h"

int main()
{
    ifstream file("1.txt");

    TextQuery tQuery(file);

    Query q = Query("GAN") & Query("and");

    cout << q.eval(tQuery);

    return 0;
}