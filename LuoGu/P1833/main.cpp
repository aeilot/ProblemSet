#include <cstdio>
#include <iostream>

using namespace std;

int C[10010], P[10010], T[10010];
int n;
int DP[1010];
int co[1000010];
int to[1000005];
bool mo[1000005];
int cnt = 0;

void pre() {
    for (int i = 1; i <= n; i++) {
        if (P[i] == 0) {
            mo[++cnt] = true;
            co[cnt] = C[i];
            to[cnt] = T[i];
        } else if (P[i] == 1) {
            co[++cnt] = C[i];
            to[cnt] = T[i];
        } else {
            int tmp = P[i];
            int c = 1;
            while (tmp - c > 0) {
                tmp -= c;
                to[++cnt] = c * T[i];
                co[cnt] = c * C[i];
                c += 2;
            }
            if (tmp > 0) {
                to[++cnt] = tmp * T[i];
                co[cnt] = tmp * C[i];
            }
        }
    }
}

int main() {
    // Type your code here
    int hs, ms, he, me;
    scanf("%d:%d%d:%d", &hs, &ms, &he, &me);
    if (ms > me) {
        me += 60;
        he--;
    }
    long long time = he * 60 + me - (hs * 60 + ms);
    // Solve
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> T[i] >> C[i] >> P[i];
    }
    pre();
    for (int i = 1; i <= cnt; i++) {
        if (mo[i] == true) {
            for (int j = to[i]; j <= time; j++) {
                DP[j] = max(DP[j], DP[j - to[i]] + co[i]);
            }
        } else {
            for (int j = time; j >= to[i]; j--) {
                DP[j] = max(DP[j], DP[j - to[i]] + co[i]);
            }
        }
    }
    cout << DP[time] << endl;
    return 0;
}