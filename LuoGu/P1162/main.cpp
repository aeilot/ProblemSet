#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int MAP[30][30];
int MAPV[30][30];
int n;

struct Loc {
    int v, i, j;
};

void bfs() {
    queue<Loc> Q;
    for (int i = 0; i < n; i++)
        if (MAP[i][0] == 0) Q.push({MAP[i][0], i, 0});
    for (int i = 0; i < n; i++)
        if (MAP[i][n - 1] == 0) Q.push({MAP[i][n - 1], i, n - 1});
    for (int i = 1; i < n - 1; i++)
        if (MAP[0][i] == 0) Q.push({MAP[0][i], 0, i});
    for (int i = 1; i < n - 1; i++)
        if (MAP[n - 1][i] == 0) Q.push({MAP[n - 1][i], n - 1, i});
    while (!Q.empty()) {
        Loc t = Q.front();
        Q.pop();
        if (t.v == 0) MAP[t.i][t.j]++;
        if (t.j > 0 && MAP[t.i][t.j - 1] == 0)
            Q.push({MAP[t.i][t.j - 1], t.i, t.j - 1});
        if (t.i > 0 && MAP[t.i - 1][t.j] == 0)
            Q.push({MAP[t.i][t.j - 1], t.i - 1, t.j});
        if (t.i < n - 1 && MAP[t.i + 1][t.j] == 0)
            Q.push({MAP[t.i][t.j - 1], t.i + 1, t.j});
        if (t.j < n - 1 && MAP[t.i][t.j + 1] == 0)
            Q.push({MAP[t.i][t.j - 1], t.i, t.j + 1});
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> MAP[i][j];
            MAPV[i][j] = MAP[i][j];
        }
    bfs();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (MAP[i][j] == 0) {
                cout << 2 << " ";
            } else {
                cout << MAPV[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}