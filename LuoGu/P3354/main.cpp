#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

struct Node {
    int to, next, d;
} NDS[201];

int head[201], vis[201];
int cnt = 0;
long long W[201];
int tot = 0;

void add(int a, int b, int d) {
    NDS[cnt].to = b;
    NDS[cnt].next = head[a];
    NDS[cnt].d = d;
    head[a] = cnt++;
}

int fa[201];
long long f[201][201][52][2];// 祖先唯一性
long long dep[201];
long long n, k;

void dp(int x) {
    fa[++tot] = x;
    vis[x] = 1;
    for (int i = head[x]; i != -1; i = NDS[i].next) {
        int y = NDS[i].to;
        if (vis[y]) continue;
        dep[y] = dep[x] + NDS[i].d;
        dp(y);
        for (int j = tot; j >= 1; j--) {
            int ff = fa[j];
            for (int l = k; l >= 0; l--) {
                f[x][ff][l][0] += f[y][ff][0][0];
                f[x][ff][l][1] += f[y][x][0][0];
                for (int s = l; s >= 0; s--) {
                    f[x][ff][l][0] = min(f[x][ff][l][0],
                                         f[x][ff][l - s][0] + f[y][ff][s][0]);
                    f[x][ff][l][1] =
                            min(f[x][ff][l][1], f[x][ff][l - s][1] + f[y][x][s][0]);
                }
            }
        }
    }
    for (int j = 1; j <= tot; j++) {
        int ff = fa[j];
        for (int l = k; l >= 0; l--) {
            if (l >= 1) {
                f[x][ff][l][0] = min(f[x][ff][l][0] + W[x] * (dep[x] - dep[ff]),
                                     f[x][ff][l - 1][1]);
            } else {
                f[x][ff][l][0] += W[x] * (dep[x] - dep[ff]);
            }
            //            cout << x << " "<<ff << " "<< l << " " <<
            //            f[x][ff][l][0] << " " << endl;
        }
    }
    //    cout << dep[x] << endl;
    tot--;
}

int main() {
    // Type your code here
    memset(head, -1, sizeof(head));
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int w, v, d;
        cin >> w >> v >> d;
        W[i] = w;
        add(i, v, d);
        add(v, i, d);
    }
    dp(0);
    cout << f[0][0][k][0] << endl;
    return 0;
}