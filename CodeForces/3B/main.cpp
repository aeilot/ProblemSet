#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;


struct Item {
    int id;
    int t;
    int p;
} Ichi[100020], Ni[100020];
int ci = 0, cn = 0;
long long p1[100020], p2[100020];

bool cmp(Item &a, Item &b) {
    return a.p > b.p;
}

int main() {
    int n, v;
    cin >> n >> v;
    for (int i = 1; i <= n; i++) {
        int t, p;
        cin >> t >> p;
        if (t == 1) {
            Ichi[ci].p = p;
            Ichi[ci].id = i;
            Ichi[ci].t = t;
            ci++;
        }
        if (t == 2) {
            Ni[cn].p = p;
            Ni[cn].id = i;
            Ni[cn].t = t;
            cn++;
        }
    }
    if (v == 1 && ci == 0) {
        cout << 0 << endl;
        return 0;
    }
    sort(Ichi, Ichi + ci, cmp);
    sort(Ni, Ni + cn, cmp);
    p1[1] = Ichi[0].p;
    p2[1] = Ni[0].p;
    for (int i = 1; i < ci; i++) {
        p1[i + 1] = p1[i] + Ichi[i].p;
    }
    for (int i = 1; i < cn; i++) {
        p2[i + 1] = p2[i] + Ni[i].p;
    }
    long long aa = 0;
    int c1, c2;
    for (int i = 0; i <= v / 2 && i <= cn; i++) {
        int nic = i;
        int ic = v - i * 2;
        if (ic > ci) ic = ci;
        long long ans = 0;
        ans += p1[ic];
        ans += p2[nic];
        if (ans > aa) {
            aa = ans;
            c2 = nic;
            c1 = ic;
        }
    }
    cout << aa << endl;
    for (int i = 0; i < c1; i++) {
        cout << Ichi[i].id << ' ';
    }
    for (int i = 0; i < c2; i++) {
        cout << Ni[i].id << ' ';
    }
    cout << endl;
    return 0;
}
