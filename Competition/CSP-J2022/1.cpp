#include <cstdio>
#include <iostream>

using namespace std;

long long quickpow(long long a, long long b) {
    if (a == 1) return 1;
    long long ans = 1;
    for (; b; b >>= 1) {
        if (a > 1000000000 || ans > 1000000000) return -1;
        if (b & 1) ans = ans * a;
        a = a * a;
    }
    if (ans > 1000000000) return -1;
    return ans;
}

int main() {
    // Type your code here
    long long a, b;
    cin >> a >> b;
    cout << quickpow(a, b) << endl;
    return 0;
}