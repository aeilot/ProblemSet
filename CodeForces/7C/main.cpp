#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

long long exgcd(long long a, long long b, long long &x, long long &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}

int main() {
    long long A, B, C;
    cin >> A >> B >> C;
    C *= -1;
    long long x, y;
    long long d = exgcd(A, B, x, y);
    if (C % d != 0)
        cout << -1 << endl;
    else {
        cout << x * (C / d) << ' ' << y * (C / d) << endl;
    }
    return 0;
}
