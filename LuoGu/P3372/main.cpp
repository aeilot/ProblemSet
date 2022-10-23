#include <cstdio>
#include <iostream>

using namespace std;

struct SegmentTree {
    long long data = 0;
    long long tag = 0;
} st[400001];

long long ar[100001];

void build(int l, int r, int p) {
    if (l == r) {
        st[p].data = ar[l];
        return;
    }
    int mid = l + ((r - l) >> 1);
    build(l, mid, 2 * p);
    build(mid + 1, r, 2 * p + 1);
    st[p].data = st[2 * p].data + st[2 * p + 1].data;
}

long long query(int l, int r, int ql, int qr, int p) {
    if (ql >= l && qr <= r) return st[p].data;
    long long sum = 0;
    int mid = ql + ((qr - ql) >> 1);
    if (st[p].tag != 0) {
        st[p * 2].data += (mid - ql + 1) * st[p].tag;
        st[p * 2].tag += st[p].tag;
        st[p * 2 + 1].data += (qr - mid) * st[p].tag;
        st[p * 2 + 1].tag += st[p].tag;
        st[p].tag = 0;
    }
    if (l <= mid) sum += query(l, r, ql, mid, p * 2);
    if (r > mid) sum += query(l, r, mid + 1, qr, p * 2 + 1);
    return sum;
}

void update(int l, int r, int p, int ql, int qr, long long tag) {
    if (l <= ql && qr <= r) {
        st[p].tag += tag;
        st[p].data += (qr - ql + 1) * tag;
        return;
    }
    int mid = ql + ((qr - ql) >> 1);
    if (ql != qr && st[p].tag != 0) {
        st[p * 2].data += (mid - ql + 1) * st[p].tag;
        st[p * 2].tag += st[p].tag;
        st[p * 2 + 1].data += (qr - mid) * st[p].tag;
        st[p * 2 + 1].tag += st[p].tag;
        st[p].tag = 0;
    }
    if (l <= mid) update(l, r, p * 2, ql, mid, tag);
    if (r > mid) update(l, r, 2 * p + 1, mid + 1, qr, tag);
    st[p].data = st[p * 2].data + st[p * 2 + 1].data;
}

int main() {
    // Type your code here
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        long long tt;
        cin >> tt;
        ar[i] = tt;
    }
    build(1, n, 1);
    for (int i = 0; i < m; i++) {
        int op;
        cin >> op;
        long long x, y, k;
        switch (op) {
            case 1:
                cin >> x >> y >> k;
                update(x, y, 1, 1, n, k);
                break;
            case 2:
                cin >> x >> y;
                cout << query(x, y, 1, n, 1) << endl;
                break;
            default:
                break;
        }
    }
    return 0;
}