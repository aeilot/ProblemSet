#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int n, m;
int MAP[400][400];

int op[8][2] = {
    {-2, 1}, {2, 1}, {1, -2}, {1, 2}, {-1, -2}, {-1, 2}, {-2, -1}, {2, -1},
};

struct Node {
    int x, y;
};

int main() {
    // Type your code here
    int x, y;
    cin >> n >> m >> x >> y;
    x--;
    y--;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            MAP[i][j] = -1;
        }
    }
    queue<Node> q;
    q.push({x, y});
    MAP[x][y] = 0;
    int i = 0;
    while (!q.empty()) {
        Node tmp = q.front();
        q.pop();
        if (MAP[tmp.x][tmp.y] != -1) {
            i = MAP[tmp.x][tmp.y];
            for (int k = 0; k < 8; k++) {
                int nx = tmp.x + op[k][0];
                int ny = tmp.y + op[k][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                    MAP[nx][ny] == -1) {
                    q.push({nx, ny});
                    MAP[nx][ny] = i + 1;
                }
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%-5d", MAP[i][j]);
        }
        cout << endl;
    }
    return 0;
}
