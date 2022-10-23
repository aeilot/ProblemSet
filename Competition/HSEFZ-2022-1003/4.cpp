#include <cstdio>
#include <iostream>

using namespace std;

int a[200001];

int main() {
    // Type your code here
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a[i] = t;
    }
    for (int i = 0; i < m; i++) {
        cout << -1 << endl;
    }
    return 0;
}