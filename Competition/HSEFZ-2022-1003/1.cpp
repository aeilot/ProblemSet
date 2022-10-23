#include <cstdio>
#include <iostream>

using namespace std;

int n, T;
int d[500001];
int p[500001];

int main() {
    // Type your code here
    cin >> n >> T;
    for (int i = 0; i <= n; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        d[i] = t1;
        if (i > 0) d[i] += d[i - 1];
        p[i] = t2;
    }
    cout << -1 << endl;
    return 0;
}