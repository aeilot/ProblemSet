#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int MAP[110];
int DP[20010];

int main() {
    // Type your code here
    int V, n;
    cin >> n >> V;
    int cnt = 0;
    for (int i = 1; i <= n; i++) cin >> MAP[i];
    DP[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = V; j >= 0; j--) {
            if (j - MAP[i] >= 0) {
                DP[j] += DP[j - MAP[i]];
            }
        }
    }
    cout << DP[V] << endl;
    return 0;
}