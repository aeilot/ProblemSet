#include <cstring>
#include <iostream>

using namespace std;

int cnt = 0x3f3f3f3f;
int fa[200001];
int dis[200001];

int find(int x) {
    if (fa[x] == x) return x;
    int tmp = fa[x];
    fa[x] = find(fa[x]);
    dis[x] += dis[tmp];
    return fa[x];
}

void uni(int x, int v) {
    int xu = find(x), vu = find(v);
    if (xu == vu) {
        cnt = min(cnt, dis[v] + 1);
    } else {
        fa[xu] = vu;
        dis[x] = dis[v] + 1;
    }
}

int main() {
    // Type your code here
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= n; i++) {
        int xx;
        cin >> xx;
        uni(i, xx);
    }
    cout << cnt << endl;
    return 0;
}