#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

struct Point {
    int x, p;

    const bool operator<(const Point& a) const { return this->x < a.x; }
} PO[1010];

long long F[1010][1010];

int main() {
    // Type your code here
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> PO[i].x >> PO[i].p;
    }
    long long ans = 0;
    sort(PO + 1, PO + N + 1);
    for (int j = N; j >= 1; j--) {
        F[j][j] = PO[j].p;
        ans = max(F[j][j], ans);
        for (int i = j - 1, now = j - 1; i >= 1; i--) {
            F[i][j] = F[i + 1][j] - PO[i + 1].p;
            while (now <= N &&
                   abs(PO[j].x - PO[now + 1].x) <= abs(PO[i].x - PO[j].x)) {
                F[i][j] = max(F[i][j], F[j][++now]);
            }
            F[i][j] += PO[i].p;
            ans = max(F[i][j], ans);
        }
    }
    for (int j = 1; j <= N; j++) {
        F[j][j] = PO[j].p;
        ans = max(F[j][j], ans);
        for (int i = j + 1, now = j + 1; i <= N; i++) {
            F[i][j] = F[i - 1][j] - PO[i - 1].p;
            while (now > 1 && PO[j].x - PO[now - 1].x <= PO[i].x - PO[j].x) {
                F[i][j] = max(F[i][j], F[j][--now]);
            }
            F[i][j] += PO[i].p;
            ans = max(F[i][j], ans);
        }
    }
    cout << ans << endl;
    return 0;
}