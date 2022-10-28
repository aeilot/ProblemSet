#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

struct p {
    int t, f, h;
} P[110];

int DP[110];

bool cmp(p a, p b) {
    return a.t < b.t;
}


int main() {
    // Type your code here
    int D, G;
    cin >> D >> G;
    for (int i = 1; i <= G; i++) {
        int t, f, h;
        cin >> t >> f >> h;
        p x;
        x.t = t;
        x.f = f;
        x.h = h;
        P[i] = x;
    }
    sort(P + 1, P + G + 1, cmp);
    DP[0] = 10;
    for (int i = 1; i <= G; i++) {
        for (int j = D; j >= 0; j--) {
            if (DP[j] - P[i].t >= 0) {
                if (j + P[i].h >= D) {
                    cout << P[i].t << endl;
                    return 0;
                }
                DP[j + P[i].h] = max(DP[j], DP[j + P[i].h]);
                DP[j] += P[i].f;
            }
        }
    }
    cout << DP[0] << endl;
    return 0;
}