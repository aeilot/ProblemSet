#include <cstdio>
#include <iostream>

using namespace std;

int ans[100001];

int main() {
    // Type your code here
    int n, k;
    cin >> n >> k;
    ans[0] = 1;
    ans[1] = 1;
    for (int i = 2; i <= n; i++) {
        int t = i - k;
        if (t < 0) t = 0;
        while (t < i) {
            ans[i] += ans[t] % 100003;  // 如果不用余数会过大！ long long 都不够
            t++;
        }
    }
    cout << ans[n] % 100003 << endl;
    return 0;
}