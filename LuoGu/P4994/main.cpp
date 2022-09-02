#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    // Type your code here
    int m;
    cin >> m;
    int n = 1;
    long long a = 0, b = 1, c = 1;
    while (1) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) {
            cout << n << endl;
            break;
        }
        n++;
    }
    return 0;
}