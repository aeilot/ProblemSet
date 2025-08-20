#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>

using namespace std;

long long A_max[100010][25], A_min[100010][25], B_max[100010][25],
        B_min[100010][25], A_min_pos[100010][25], A_max_neg[100010][25];
int LLOG[100010];

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        A_max[i][0] = A_min[i][0] = a;
        if (a > 0)
            A_max_neg[i][0] = INT_MIN;
        else
            A_max_neg[i][0] = a;
        if (a < 0)
            A_min_pos[i][0] = INT_MAX;
        else
            A_min_pos[i][0] = a;
    }
    for (int i = 1; i <= m; i++) {
        int a;
        cin >> a;
        B_max[i][0] = B_min[i][0] = a;
    }
    for (int i = 2; i <= max(m, n); i++) LLOG[i] = LLOG[i / 2] + 1;
    for (int i = 1; i <= LLOG[n]; i++) {
        for (int j = 1; j + (1 << i) - 1 <= n; j++) {
            A_max[j][i] =
                    max(A_max[j][i - 1], A_max[j + (1 << (i - 1))][i - 1]);
            A_min[j][i] =
                    min(A_min[j][i - 1], A_min[j + (1 << (i - 1))][i - 1]);
            A_max_neg[j][i] =
                    max(A_max_neg[j][i - 1], A_max_neg[j + (1 << (i - 1))][i - 1]);
            A_min_pos[j][i] =
                    min(A_min_pos[j][i - 1], A_min_pos[j + (1 << (i - 1))][i - 1]);
        }
    }
    for (int i = 1; i <= LLOG[m]; i++) {
        for (int j = 1; j + (1 << i) - 1 <= m; j++) {
            B_max[j][i] =
                    max(B_max[j][i - 1], B_max[j + (1 << (i - 1))][i - 1]);
            B_min[j][i] =
                    min(B_min[j][i - 1], B_min[j + (1 << (i - 1))][i - 1]);
        }
    }
    // Q
    while (q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int d1 = LLOG[r1 - l1 + 1];
        int d2 = LLOG[r2 - l2 + 1];
        long long amx = max(A_max[l1][d1], A_max[r1 - (1 << d1) + 1][d1]);
        long long amn = min(A_min[l1][d1], A_min[r1 - (1 << d1) + 1][d1]);
        long long bmx = max(B_max[l2][d2], B_max[r2 - (1 << d2) + 1][d2]);
        long long bmn = min(B_min[l2][d2], B_min[r2 - (1 << d2) + 1][d2]);
        long long amx_ng =
                max(A_max_neg[l1][d1], A_max_neg[r1 - (1 << d1) + 1][d1]);
        long long amn_ps =
                min(A_min_pos[l1][d1], A_min_pos[r1 - (1 << d1) + 1][d1]);
        long long ans = LLONG_MIN;
        if (amx >= 0) {
            ans = max(ans, amx * bmn);
        }
        if (amn <= 0) {
            ans = max(ans, amn * bmx);
        }
        if (bmx >= 0 && amx_ng != INT_MIN) ans = max(ans, amx_ng * bmx);
        if (bmn <= 0 && amn_ps != INT_MAX) ans = max(ans, amn_ps * bmn);
        cout << ans << endl;
    }
    return 0;
}
