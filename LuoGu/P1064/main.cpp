#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct Obj {
    int v, q;
    long long p;
};

Obj mai[62];
vector<Obj> annex[62];
long long DP[32010];

int main() {
    int n, m;
    cin >> n >> m;
    int mm = 0;
    for (int i = 1; i <= m; i++) {
        int v, p, q;
        cin >> v >> p >> q;
        Obj t;
        t.v = v;
        t.p = p * v;
        if (q == 0) {
            t.q = 0;
            q = i;
            mai[i] = t;
            mm = max(mm, i);
        } else {
            t.q = q;
            annex[q].push_back(t);
        }
    }
    for (int i = 0; i <= mm; i++) {
        for (int v = n; v >= 0; v--) {
            if (annex[i].size() == 0) {
                DP[v] =
                    max(DP[v],
                        (v - mai[i].v >= 0) ? DP[v - mai[i].v] + mai[i].p : 0);
            } else if (annex[i].size() == 1) {
                DP[v] = max(
                    DP[v],
                    max((v - mai[i].v >= 0) ? DP[v - mai[i].v] + mai[i].p : 0,
                        (v - mai[i].v - annex[i][0].v >= 0)
                            ? DP[v - mai[i].v - annex[i][0].v] + mai[i].p +
                                  annex[i][0].p
                            : 0));
            } else {
                DP[v] = max(
                    max(DP[v],
                        (v - mai[i].v - annex[i][0].v - annex[i][1].v >= 0)
                            ? DP[v - mai[i].v - annex[i][0].v - annex[i][1].v] +
                                  mai[i].p + annex[i][0].p + annex[i][1].p
                            : 0),
                    max((v - mai[i].v >= 0) ? DP[v - mai[i].v] + mai[i].p : 0,
                        (v - mai[i].v - annex[i][0].v >= 0)
                            ? DP[v - mai[i].v - annex[i][0].v] + mai[i].p +
                                  annex[i][0].p
                            : 0));
            }
        }
    }
    cout << DP[n] << endl;
    return 0;
}