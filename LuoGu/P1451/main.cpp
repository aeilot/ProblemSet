#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>

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
        if (MAP[cx][cy + 1] != '0' && VIS[cx][cy + 1] == 0) {
            BQ.push({cx, cy + 1});
            VIS[cx][cy + 1] = 1;
        }
        if (MAP[cx][cy - 1] != '0' && VIS[cx][cy - 1] == 0) {
            BQ.push({cx, cy - 1});
            VIS[cx][cy - 1] = 1;
        }
        if (MAP[cx + 1][cy] != '0' && VIS[cx + 1][cy] == 0) {
            BQ.push({cx + 1, cy});
            VIS[cx + 1][cy] = 1;
        }
        if (MAP[cx - 1][cy] != '0' && VIS[cx - 1][cy] == 0) {
            BQ.push({cx - 1, cy});
            VIS[cx - 1][cy] = 1;
        }
    }
}

int main() {
    // Type your code here
    memset(VIS, 0, sizeof(VIS));
    int N, M;
    cin >> N >> M;
    char t;
    for (int i = 1; i <= N; i++) {
        MAP[i][0] = '0';
        MAP[i][M + 1] = '0';
    }
    for (int i = 1; i <= M; i++) {
        MAP[0][i] = '0';
        MAP[N + 1][i] = '0';
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> t;
            MAP[i][j] = t;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (MAP[i][j] != '0' && VIS[i][j] == 0) {
                cnt++;
                bfs(i, j);
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
