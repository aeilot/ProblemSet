#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

char MAP[110][110];
int VIS[110][110];

struct POS {
    int x, y;
};

void bfs(int x, int y) {
    queue<POS> BQ;
    BQ.push({x, y});
    VIS[x][y] = 1;
    while (!BQ.empty()) {
        POS cur = BQ.front();
        BQ.pop();
        int cx = cur.x;
        int cy = cur.y;
        if (MAP[cx][cy + 1] == 'W' && VIS[cx][cy + 1] == 0) {
            BQ.push({cx, cy + 1});
            VIS[cx][cy + 1] = 1;
        }
        if (MAP[cx][cy - 1] == 'W' && VIS[cx][cy - 1] == 0) {
            BQ.push({cx, cy - 1});
            VIS[cx][cy - 1] = 1;
        }
        if (MAP[cx + 1][cy] == 'W' && VIS[cx + 1][cy] == 0) {
            BQ.push({cx + 1, cy});
            VIS[cx + 1][cy] = 1;
        }
        if (MAP[cx - 1][cy] == 'W' && VIS[cx - 1][cy] == 0) {
            BQ.push({cx - 1, cy});
            VIS[cx - 1][cy] = 1;
        }
        if (MAP[cx + 1][cy + 1] == 'W' && VIS[cx + 1][cy + 1] == 0) {
            BQ.push({cx + 1, cy + 1});
            VIS[cx + 1][cy + 1] = 1;
        }
        if (MAP[cx - 1][cy + 1] == 'W' && VIS[cx - 1][cy + 1] == 0) {
            BQ.push({cx - 1, cy + 1});
            VIS[cx - 1][cy + 1] = 1;
        }
        if (MAP[cx + 1][cy - 1] == 'W' && VIS[cx + 1][cy - 1] == 0) {
            BQ.push({cx + 1, cy - 1});
            VIS[cx + 1][cy - 1] = 1;
        }
        if (MAP[cx - 1][cy - 1] == 'W' && VIS[cx - 1][cy - 1] == 0) {
            BQ.push({cx - 1, cy - 1});
            VIS[cx - 1][cy - 1] = 1;
        }
    }
}

int main() {
    // Type your code here
    memset(VIS, 0, sizeof(VIS));
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> MAP[i][j];
        }
    }
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (MAP[i][j] == 'W' && VIS[i][j] == 0) {
                cnt++;
                bfs(i, j);
            }
        }
    }
    cout << cnt << endl;
    return 0;
}