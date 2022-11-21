#include <cstdio>
#include <iostream>

using namespace std;

int AR[510];
int m, k;

bool checker(int mid) {
    int now = 1, t = 0;
    for (int i = m; i >= 1; i--) {
        if (AR[i] + t > mid) t = 0, now++;
        t += AR[i];
    }
    return now <= k;
}

int main() {
    // Type your code here
    cin >> m >> k;
    int l = 0, r = 0, mid;
    for (int i = 1; i <= m; i++) {
        cin >> AR[i];
        r += AR[i];
    }
    while (l + 1 < r) {
        mid = (l + r) >> 1;
        if (checker(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    int now = 1, t = 0;
    int x[510], y[510];
    y[1] = m;
    for (int i = m; i >= 1; i--) {
        if (AR[i] + t > r) {
            x[now] = i + 1;
            y[++now] = i;
            t = 0;
        }
        t += AR[i];
    }
    x[now] = 1;
    for (int i = now; i >= 1; i--) {
        cout << x[i] << " " << y[i] << endl;
    }
    return 0;
}