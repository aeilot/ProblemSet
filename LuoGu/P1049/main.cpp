#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int MAP[40];
int DP[20010];

int main() {
    // Type your code here
    int V, n;
    cin >> V >> n;
    for (int i = 1; i <= n; i++) cin >> MAP[i];
    for (int i = 1; i <= n; i++) {
        for (int j = V; j >= 0; j--) {
            if (j - MAP[i] >= 0) DP[j] = max(DP[j], DP[j - MAP[i]] + MAP[i]);
        }
    }
    cout << V - DP[V] << endl;
    return 0;
}