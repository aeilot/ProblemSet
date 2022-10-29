#include <climits>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

#define MOD 2147483647

struct Node {
    int from, to, next;
} NDS[32010];

int vis[32010], head[32010], cnt = 0, f[32010], w[16010];

void add(int a, int b) {
    NDS[cnt].from = a;
    NDS[cnt].to = b;
    NDS[cnt].next = head[a];
    head[a] = cnt++;
}

void DFS(int x) {
    vis[x] = 1;
    for (int i = head[x]; i != -1; i = NDS[i].next) {
        int y = NDS[i].to;
        if (vis[y] == 1) continue;
        DFS(y);
        f[x] = max(f[x], f[x] + f[y]);
        f[x] %= MOD;
    }
}

int main() {
    // Type your code here
    memset(head, -1, sizeof(head));
    memset(vis, 0, sizeof(vis));
    memset(f, 0, sizeof(f));
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> w[i];
        f[i] = w[i];
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        add(a, b);
        add(b, a);
    }
    int aans = INT_MIN;
    DFS(0);
    for (int i = 0; i < N; i++) {
        aans = max(f[i], aans);
    }
    cout << aans << endl;
    return 0;
}