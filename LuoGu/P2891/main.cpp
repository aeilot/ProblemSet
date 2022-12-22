#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int to, next;
    long long c;
} NDS[400001];

int cnt = 2, head[400001];

void add(int from, int to, long long c) {
    NDS[cnt].to = to;
    NDS[cnt].next = head[from];
    NDS[cnt].c = c;
    head[from] = cnt++;

    NDS[cnt].to = from;
    NDS[cnt].next = head[to];
    NDS[cnt].c = 0;
    head[to] = cnt++;
}

int d[400001];
int cur[400001];
int s = 0, ter;
bool bfs() {
    memset(d, 0, sizeof(d));
    queue<int> qq;
    cur[s] = head[s];
    d[0] = 1;
    qq.push(0);
    while (!qq.empty()) {
        int now = qq.front();
        qq.pop();
        for (int i = head[now]; i != -1; i = NDS[i].next) {
            int y = NDS[i].to;
            long long c = NDS[i].c;
            if (c > 0 && d[y] == 0) {
                d[y] = d[now] + 1;
                qq.push(y);
                cur[y] = head[y];
            }
        }
    }
    if (d[ter] != 0) return true;
    return false;
}

long long dinic(int x, long long flow) {
    if (x == ter) return flow;
    long long rst = 0, k;
    for (int i = cur[x]; i != -1 && flow; i = NDS[i].next) {
        int y = NDS[i].to;
        cur[x] = i;
        long long c = NDS[i].c;
        if (c > 0 && d[y] == d[x] + 1) {
            k = dinic(y, min(flow, c));
            if (k != 0) {
                NDS[i].c -= k;
                NDS[i ^ 1].c += k;
                flow -= k;
                rst += k;
            } else
                d[y] = 0;
        }
    }
    return rst;
}
int N, F, D;
int main() {
    memset(head, -1, sizeof(head));
    cin >> N >> F >> D;
    ter = 2 * N + F + D + 1;
    s = 0;
    for (int i = 1; i <= F; i++) {
        add(0, i, 1);
    }
    for (int i = 1; i <= N; i++) {
        add(i + F, i + F + N, 1);
    }
    for (int i = 1; i <= D; i++) {
        add(i + F + 2 * N, ter, 1);
    }
    for (int i = 1; i <= N; i++) {
        int fi, di;
        cin >> fi >> di;
        while (fi--) {
            int fc;
            cin >> fc;
            add(fc, i + F, 1);
        }
        while (di--) {
            int fc;
            cin >> fc;
            add(i + F + N, fc + 2 * N + F, 1);
        }
    }
    long long mflow = 0;
    while (bfs()) {
        mflow += dinic(s, LLONG_MAX);
    }
    cout << mflow << endl;
    return 0;
}
