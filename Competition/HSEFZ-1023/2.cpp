#include <cstdio>
#include <iostream>

using namespace std;

struct carpet {
    int x, y, a, b;
    bool over(int x1, int y1, int x2, int y2) {
        return x1 >= x && x1 <= a && y1 >= y && y1 <= b && x2 >= x && x2 <= a &&
               y2 >= y && y2 <= b;
    }
} cp[300001];

int main() {
    // Type your code here
    int T;
    int P, Q, n;
    cin >> T >> P >> Q >> n;
    for (int i = 0; i < n; i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        cp[i].x = x;
        cp[i].y = y;
        cp[i].a = a;
        cp[i].b = b;
    }
    int ans = 0;
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < Q; j++) {
            int aa = 0;
            for (int z = 0; z < n; z++) {
                if (cp[z].over(i, j, i + 1, j + 1)) aa++;
            }
            if (aa >= n - 1) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}