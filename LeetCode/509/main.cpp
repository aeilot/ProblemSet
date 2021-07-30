#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int a[40];
    a[0] = 0;
    a[1] = 1;

    cout << "{0,1";
    for (int i = 2; i < 40; i++) {
        a[i] = a[i - 1] + a[i - 2];
        cout << "," << a[i];
    }
    cout << "}" << endl;
    return 0;
}
