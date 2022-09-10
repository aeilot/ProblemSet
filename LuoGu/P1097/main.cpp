#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int aa[200000];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> aa[i];
    }
    sort(aa, aa + n);
    int stp = 0;
    int tmp = -1;
    for (int i = 0; i < n; i++) {
        if (tmp != aa[i]) {
            if (tmp != -1) {
                cout << tmp << " " << stp << endl;
            }
            tmp = aa[i];
            stp = 0;
        }
        stp++;
    }
    cout << tmp << " " << stp << endl;
    return 0;
}