#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int A[2010], B[2010];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> B[i];
    }
    sort(A + 1, A + n + 1, greater<int>());
    sort(B + 1, B + n + 1, greater<int>());
    long long ans = 0;
    for (int i = 1, ii = n, jj = n, j = 1;
         i <= n && j <= n && ii >= 1 && ii >= i && jj >= 1 && jj >= j;) {
        if (A[i] > B[j]) {
            i++;
            j++;
            ans++;
        } else if (A[i] < B[j]) {
            ii--;
            j++;
            ans--;
        } else {
            if (A[ii] > B[jj]) {
                ii--;
                jj--;
                ans++;
            } else {
                if (A[ii] < B[j]) ans--;
                ii--;
                j++;
            }
        }
    }
    cout << ans * 200 << endl;
    return 0;
}
