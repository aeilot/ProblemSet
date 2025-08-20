#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;


struct JK {
    long long a;
    long long b;
} A[100020];

bool cmp(const JK &a, const JK &b) {
    if (a.a + a.b == b.a + b.b) {
        return a.a < b.a;
    }
    return a.a + a.b < b.a + b.b;
}

bool cmp2(const JK &a, const JK &b) {
    return a.b < b.b;
}

int main() {
    freopen("boast.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i].a >> A[i].b;
    }
    sort(A, A + n, cmp);
    long long ans = A[0].a + A[1].a + A[2].a;
    sort(A, A + 3, cmp2);
    ans += max(A[0].b, A[1].b) + max(A[1].b, A[2].b);
    cout << ans << endl;
    return 0;
}
