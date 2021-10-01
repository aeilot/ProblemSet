#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 100001;

struct MJ {
    int d1, d2;
    int i;
};

MJ ARR[MAXN];

int distance(int x1, int y1, int x2, int y2) {
    return pow(x1 - x2, 2) + pow(y1 - y2, 2);
}

bool cmp(const MJ &a, const MJ &b) { return a.d1 > b.d1; }

int main() {
    int x1, y1, x2, y2, n;
    cin >> x1 >> y1 >> x2 >> y2 >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ARR[i].d1 = distance(x1, y1, a, b);
        ARR[i].d2 = distance(x2, y2, a, b);
        ARR[i].i = i;
    }
    sort(ARR, ARR + n, cmp);
    int r1 = ARR[0].d1;
    int r2 = 0;
    int ans = r1 + r2;
    for (int i = 1; i < n; i++) {
        r2 = max(r2, ARR[i - 1].d2);
        r1 = ARR[i].d1;
        ans = min(r1 + r2, ans);
    }
    cout << ans;
    return 0;
}