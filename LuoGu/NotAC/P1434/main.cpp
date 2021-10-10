#include <cstdio>
#include <iostream>

int MAP[100][100];
int r, c;

using namespace std;

int main(int argc, char *argv[]) {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int m;
            cin >> m;
            MAP[i][j] = m;
        }
    }
    
    return 0;
}
