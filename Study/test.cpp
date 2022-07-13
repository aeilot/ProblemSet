#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    char* a = new char(100);
    gets(a);
    cout << a << endl;
    string b;
    getline(cin, b);
    cout << b << endl;
    return 0;
}