#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

int ST[1000010][50];

int main() {
    // Type your code here
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> ST[i][0];
    }
    for (int i = 1; i <= log2(n); i++) {
        for (int j = 1; j + (1 << i) - 1 <= n; j++) {
            ST[j][i] = min(ST[j][i - 1], ST[j + (1 << (i - 1))][i - 1]);
        }
    }
    int s = log2(m);
    for (int i = 1; i + m - 1 <= n; i++) {
        int y = i + m - 1;
        cout << min(ST[i][s], ST[y - (1 << s) + 1][s]) << endl;
    }
    return 0;
}