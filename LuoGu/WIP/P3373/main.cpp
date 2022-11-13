#include <cstdio>
#include <iostream>

using namespace std;

struct SGT {
    long long sum;
    long long lazytagM;
    long long lazytagA;
} NDS[400010];

int AR[100010];
int DEFP;

void build(int sl, int sr, int p) {
    NDS[p].lazytagM = 1;
    if (sl == sr) {
        NDS[p].sum = AR[sl];
        return;
    }
    int mid = (sl + sr) >> 1;
    build(sl, mid, p * 2);
    build(mid + 1, sr, p * 2 + 1);
    NDS[p].sum = NDS[p * 2].sum + NDS[p * 2 + 1].sum;
    NDS[p].sum %= DEFP;
}

long long query(int l, int r, int sl, int sr, int p) {
    if (l <= sl && sr <= r) {
        return NDS[p].sum;
    }
    int mid = (sl + sr) >> 1;
    long long sum = 0;
    if (sl <= mid) sum += query(l, r, sl, mid, p * 2);
    if (sr > mid) sum += query(l, r, mid + 1, sr, p * 2 + 1);
    return sum;
}

void add(int l, int r, int sl, int sr, int p, long long ad) {
    if (l <= sl && sr <= r) {
        NDS[p].lazytagA = (NDS[p].lazytagA + ad) % DEFP;
        NDS[p].sum = NDS[p].sum + ad * (sr - sl + 1);
        return;
    }
    int mid = (sl + sr) >> 1;
    if (sl <= mid) add(l, r, sl, mid, p * 2, ad);
    if (sr > mid) add(l, r, mid + 1, sr, p * 2 + 1, ad);
}

void mul(int l, int r, int sl, int sr, int p, long long ad) {
    if (l <= sl && sr <= r) {
        NDS[p].lazytagA = (NDS[p].lazytagA * ad);
        NDS[p].sum = NDS[p].sum + ad * NDS[p].sum;
        return;
    }
    int mid = (sl + sr) >> 1;
    if (sl <= mid) add(l, r, sl, mid, p * 2, ad);
    if (sr > mid) add(l, r, mid + 1, sr, p * 2 + 1, ad);
}

int main() {
    // Type your code here
    int n, m;
    cin >> n >> m >> DEFP;
    for (int i = 1; i <= n; i++) {
        cin >> AR[i];
    }
    build(1, n, 1);
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        long long a, b, c;
        switch (x) {
            case 1:
                cin >> a >> b >> c;
                mul(a, b, 1, n, 1, c);
                break;
            case 2:
                cin >> a >> b >> c;
                add(a, b, 1, n, 1, c);
                break;
            case 3:
                cin >> a >> b;
                cout << query(a, b, 1, n, 1) % DEFP << endl;
                break;
        }
    }
    return 0;
}
