#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    // Type your code here
    long long a, b, n;
    cin >> a >> b >> n;
    long long d = b - a;
    long long ans = n * a + d * (n - 1) * n / 2; // 用 long long 避免错误
    cout << ans << endl;
    return 0;
}