#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;
int MAP[20][20];
int op[12][2] = {{2, 2},  {-2, -2}, {2, -2}, {-2, 2}, {1, -2},  {1, 2},
                 {-1, 2}, {-1, -2}, {2, 1},  {2, -1}, {-2, -1}, {-2, 1}};
struct Node {
    int x, y;

    void init() {
        x--;
        y--;
    }
};

int main() {
    // Type your code here
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            MAP[i][j] = -1;
        }
    }
    Node black, white;
    cin >> black.x >> black.y >> white.x >> white.y;
    black.init();
    white.init();
    MAP[black.x][black.y] = 0;
    queue<Node> q;
    int i = 0;
    q.push(black);
    int n = 20;
    int m = 20;
    while (!q.empty()) {
        Node tmp = q.front();
        q.pop();
        if (MAP[tmp.x][tmp.y] != -1) {
            i = MAP[tmp.x][tmp.y];
            for (int k = 0; k < 12; k++) {
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
    cout << MAP[0][0] << endl;
    for (i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            MAP[i][j] = -1;
        }
    }
    MAP[white.x][white.y] = 0;
    q.push(white);
    while (!q.empty()) {
        Node tmp = q.front();
        q.pop();
        if (MAP[tmp.x][tmp.y] != -1) {
            i = MAP[tmp.x][tmp.y];
            for (int k = 0; k < 12; k++) {
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
    cout << MAP[0][0] << endl;
    return 0;
}