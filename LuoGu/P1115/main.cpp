#include <climits>
#include <cstdio>
#include <iostream>
using namespace std;

long long MAP[200010];
long long DP[200010];

int main() {
    // Type your code here
    int n;
    cin >> n;
    long long ans = LLONG_MIN;
    for (int i = 1; i <= n; i++) {
        cin >> MAP[i];
        DP[i] = max(DP[i - 1] + MAP[i], MAP[i]);
        ans = max(DP[i], ans);
    }
    cout << ans << endl;
    return 0;
}