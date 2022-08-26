#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

int calc(int num, int last) {
    // cout << num << endl;
    int ans = 1;
    int c = pow(10, ((int)log10(num) + 1));
    for (int i = 1; i <= last / 2; i++) {
        ans += calc(c * i + num, i);
    }
    return ans;
}

int f[1001];

int main() {
    // Type your code here
    int n;
    cin >> n;
    f[1] = 1;
    f[0] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i / 2; j++) {
            f[i] += f[j];
        }
        f[i]++;
    }
    cout << f[n] << endl;
    return 0;
}