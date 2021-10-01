#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int ARR[100001];
int n = 0;
int d1[100001];
int c1 = 0;
int d2[100001];
int c2 = 0;

int main() {
    while (cin >> ARR[n]) n++;
    d1[0] = ARR[0];
    d2[0] = ARR[0];
    for (int i = 1; i < n; i++) {
        if (ARR[i] <= d1[c1])
            d1[++c1] = ARR[i];
        else {
            int j = upper_bound(d1, d1 + c1, ARR[i], greater<int>()) - d1;
            d1[j] = ARR[i];
        }
        if (ARR[i] > d2[c2])
            d2[++c2] = ARR[i];
        else {
            int j = lower_bound(d2, d2 + c2, ARR[i]) - d2;
            d2[j] = ARR[i];
        }
    }
    cout << c1 + 1 << endl
         << c2 + 1 << endl;
    return 0;
}