#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

long long C[500001];
long long A[500001];
int n, m;

int lowbit(int x) { return x & (-x); }

long long query(int x) {
    long long ans = 0;
    while (x != 0) {
        ans += C[x];
        x -= lowbit(x);
    }
    return ans;
}

void add(int x, int k) {
    while (x <= n) {
        C[x] += k;
        x += lowbit(x);
    }
}

void init() {
    for (int i = 1; i <= n; i++) {
        add(i, A[i]);
    }
}

int main() {
    // Type your code here
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    init();
    while (m--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) add(x, y);
        if (op == 2) cout << query(y) - query(x - 1) << endl;
    }
    return 0;
}