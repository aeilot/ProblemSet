#include <cstdio>
#include <iostream>

using namespace std;

int A[1010];
int N;

int f[1010][1010];

int main() {
    // Type your code here
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j >= 1)
                f[i][j] = max(f[i - 1][j] + (A[i] == i - j), f[i - 1][j - 1]);
            else {
                f[i][j] = f[i - 1][j] + (A[i] == i - j);
            }
        }
    }
    `ccc 28 int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            ans = max(ans, f[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}