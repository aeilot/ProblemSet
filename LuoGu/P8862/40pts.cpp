#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

long long A[100010];

struct Node {
    long long v;
    long long tg;
} NDS[400040];

int n, m;

void build(int l, int r, int pl, int pr, int p) {
    NDS[p].tg = 0;
    if (pl == pr) {
        NDS[p].v = A[pl];
        return;
    }
    int mid = pr + ((pl - pr) >> 1);
    build(l, r, pl, mid, p * 2);
    build(l, r, mid + 1, pr, p * 2 + 1);
    NDS[p].v = min(NDS[p * 2].v, NDS[p * 2 + 1].v);
}

void add(int l, int r, int pl, int pr, long long k, int p) {
    if (pl >= l && pr <= r) {
        NDS[p].v += k;
        NDS[p].tg += k;
        return;
    }
    int mid = pr + ((pl - pr) >> 1);
    if (NDS[p].tg != 0 && l != r) {
        NDS[p * 2].tg += NDS[p].tg;
        NDS[p * 2].v += NDS[p].tg;
        NDS[p * 2 + 1].tg += NDS[p].tg;
        NDS[p * 2 + 1].v += NDS[p].tg;
        NDS[p].tg = 0;
    }
    if (l <= mid) {
        add(l, r, pl, mid, k, p * 2);
    }
    if (r > mid) {
        add(l, r, mid + 1, pr, k, p * 2 + 1);
    }
    NDS[p].v = min(NDS[p * 2].v, NDS[p * 2 + 1].v);
}

long long get(int l, int r, int pl, int pr, int p) {
    if (pl >= l && pr <= r) {
        return NDS[p].v;
    }
    int mid = pr + ((pl - pr) >> 1);
    long long ans = LLONG_MAX;
    if (NDS[p].tg != 0 && l != r) {
        NDS[p * 2].tg += NDS[p].tg;
        NDS[p * 2].v += NDS[p].tg;
        NDS[p * 2 + 1].tg += NDS[p].tg;
        NDS[p * 2 + 1].v += NDS[p].tg;
        NDS[p].tg = 0;
    }
    if (l <= mid) {
        ans = min(get(l, r, pl, mid, p * 2), ans);
    }
    if (r > mid) {
        ans = min(get(l, r, mid + 1, pr, p * 2 + 1), ans);
    }
    return ans;
}

struct Step {
    int type;
    long long op1, op2, op3;
} OPs[100010];

void clear() {
    for (auto &i : NDS) {
        i.tg = 0;
        i.v = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    long long T;
    cin >> T;
    while (T--) {
        n = 0;
        m = 0;
        clear();
        memset(A, 0, sizeof(A));
        vector<long long> ops;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            long long b;
            cin >> b;
        }
        for (int i = 1; i <= m; i++) {
            long long a;
            cin >> a;
            if (a == 1) {
                long long l, r, x;
                cin >> l >> r >> x;
                OPs[i].op1 = l;
                OPs[i].op2 = r;
                OPs[i].op3 = x;
                OPs[i].type = 1;
            } else {
                int l, r;
                cin >> l >> r;
                OPs[i].op1 = l;
                OPs[i].op2 = r;
                OPs[i].op3 = 0;
                OPs[i].type = 2;
            }
        }
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }
        build(1, n, 1, n, 1);
        for (int i = m; i >= 1; i--) {
            Step stp = OPs[i];
            if (stp.type == 1) {
                add(stp.op1, stp.op2, 1, n, -stp.op3, 1);
            } else {
                ops.push_back(get(stp.op1, stp.op2, 1, n, 1));
            }
        }
        for (int i = ops.size() - 1; i >= 0; i--) {
            cout << ops[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}