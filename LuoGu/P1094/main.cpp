#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int ar[30001];

int main() {
    int n, w;
    cin >> w >> n;
    for (int i = 0; i < n; i++) cin >> ar[i];
    sort(ar, ar + n);
    int ans = 0;
    int l = 0;
    int r = n - 1;
    while (r >= l) {
        if (ar[l] + ar[r] <= w) {
            l++;
            r--;
            ans++;
        } else {
            r--;
            ans++;
        }
    }
    cout << ans;
    return 0;
}