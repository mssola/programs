/*
 * Copyright (C) 2014 Miquel Sabaté Solà <mikisabate@gmail.com>
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(int argc, char *argv[])
{
    vector<string> v;

    // Adding elements through a lambda expression.
    auto l = [&v](string x) { v.push_back(x); };
    l("hello");
    l("bye");
    for (auto s : v)
        cout << s << endl;

    // Using the "for_each" new function.
    for_each(v.begin(), v.end(), [](string &x) {
        if (x.size() > 0)
            x[0] = toupper(x[0]);
    });
    for (auto s : v)
        cout << s << endl;
}
