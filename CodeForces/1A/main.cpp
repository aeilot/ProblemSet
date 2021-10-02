#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    double n, m, a;  // Wow, it's n and m and a!
    cin >> n >> m >> a;
    long long ans = ceil(n / a) * ceil(m / a);
    cout << ans << endl;
    return 0;
}