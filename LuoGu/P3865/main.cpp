#include <cstdio>
#include <iostream>

using namespace std;

int n, m;
int LG[100010];
int ST[100010][22];

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}

void pre() {
    for (int i = 1; i <= LG[n]; i++) {
        for (int j = 1; j + (1 << i) - 1 <= n; j++) {
            ST[j][i] = max(ST[j][i - 1], ST[j + (1 << (i - 1))][i - 1]);
        }
    }
}

int main() {
    // Type your code here
    n = read();
    m = read();
    LG[1] = 0;
    LG[2] = 1;
    for (int i = 3; i <= n; i++) {
        LG[i] = LG[i / 2] + 1;
    }
    for (int i = 1; i <= n; i++) {
        ST[i][0] = read();
    }
    pre();
    for (int i = 1; i <= m; i++) {
        int x, y;
        x = read();
        y = read();
        int s = LG[y - x + 1];
        printf("%d\n", max(ST[x][s], ST[y - (1 << s) + 1][s]));
    }
    return 0;
}