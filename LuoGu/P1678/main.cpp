#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>

using namespace std;

int SCH[100000];
int STU[100000];

int main(int argc, char *argv[]) {
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++) cin >> SCH[i];
    for (int i = 0; i < n; i++) cin >> STU[i];
    sort(STU, STU + n);
    sort(SCH, SCH + m);
    int dis = 0;
    for (int i = 0; i < n; i++) {
        int c = lower_bound(SCH, SCH + m, STU[i]) - SCH;
        int nxt = SCH[c];
        if (c < 1) {
            dis += abs(STU[i] - nxt);
        } else {
            int prv = SCH[c - 1];
            dis += min(abs(STU[i] - nxt), abs(STU[i] - prv));
        }
    }
    cout << dis << endl;
    return 0;
}
