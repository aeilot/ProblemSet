#include <climits>
#include <cstdio>
#include <iostream>

using namespace std;

int MP[100010];
int n, m;

bool check(long long x) {
    int num = 1;
    long long sm = 0;
    for (int i = 1; i <= n; i++) {
        if (sm + MP[i] > x) {
            sm = 0;
            num++;
        }
        sm += MP[i];
    }
    return num > m;
}

int main() {
    // Type your code here
    cin >> n >> m;
    long long l = 0, r = 0, mid;
    for (int i = 1; i <= n; i++) {
        cin >> MP[i];
        l = max(l, (long long) MP[i]);
        r += MP[i];
    }
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << l << endl;
    return 0;
}