#include <cstdio>
#include <iostream>

using namespace std;


int main() {
    long long a, b, p;
    cin >> a >> b >> p;
    printf("%lld^%lld mod %lld=", a, b, p);
    long long s = 1;
    for (; b != 0; b >>= 1) {
        if (b & 1) s = s * a % p;
        a = a * a % p;
    }
    printf("%lld\n", s);
    return 0;
}