#include <cstdio>
#include <iostream>

using namespace std;

int flag[10000];

int main() {
    // Type your code here
    int l, m;
    cin >> l >> m;
    for (int i = 0; i <= l; i++) {
        flag[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        for (int j = a; j <= b; j++) {
            flag[j] = 0;
        }
    }
    int c = 0;
    for (int i = 0; i <= l; i++) {
        if (flag[i] == 1) c++;
    }
    cout << c << endl;
    return 0;
}