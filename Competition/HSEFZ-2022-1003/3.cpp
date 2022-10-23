#include <climits>
#include <cstdio>
#include <iostream>

using namespace std;

int N, Q;
int P[200001];
int PD[200001];

struct SegmentTree {
    int l, r, v;
} st[400001];

void build(int l, int r, int cnt) {
    st[cnt].l = l;
    st[cnt].r = r;
    if (l == r) {
        st[cnt].v = PD[l];
        return;
    }
    int mid = l + ((r - l) >> 1);
    build(l, mid, cnt * 2);
    build(mid + 1, r, cnt * 2 + 1);
    st[cnt].v = max(st[cnt * 2].v, st[cnt * 2 + 1].v);
}

int query(int l, int r, int p) {
    int s = st[p].l;
    int t = st[p].r;
    if (s >= l && t <= r) return st[p].v;
    int mid = s + ((t - s) >> 1);
    int max1 = INT_MIN;
    if (l <= mid) max1 = max(max1, query(l, r, p * 2));
    if (r > mid) max1 = max(max1, query(l, r, p * 2 + 1));
    return max1;
}

int main() {
    // Type your code here
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        P[i] = t;
    }
    int lstX = 0;
    int X = -1, L, R;
    for (int i = 0; i < Q; i++) {
        lstX = X;
        cin >> X >> L >> R;
        if (lstX != X) {
            for (int j = 0; j < N; j++) {
                PD[j] = X ^ P[j];
            }
            build(0, N - 1, 1);
        }
        int mm = query(L, R, 1);
        cout << mm << endl;
    }
    return 0;
}