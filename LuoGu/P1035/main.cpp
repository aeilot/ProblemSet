#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    // Type your code here
    int k;
    cin >> k;
    double sn = 0;
    int n = 1;
    while (sn <= k) {
        sn += 1 / double(n);
        n++;
    }
    cout << n - 1 << endl;
    return 0;
}