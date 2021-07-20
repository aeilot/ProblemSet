#include <stdio.h>

#include <iostream>

using namespace std;

#define MAX_N 10000

class DT {
   public:
    int a, b, c, d;

    DT() { a = b = c = d = 0; }

    DT(int a, int b, int c, int d) {
        this->a = a;
        this->b = b;
        this->c = a + c;
        this->d = b + d;
    }

    bool judge(int x, int y) { return x >= a && x <= c && y >= b && y <= d; }
};

int main() {
    int n, x, y;
    cin >> n;
    DT dt[MAX_N];
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        dt[i] = DT(a, b, c, d);
    }
    cin >> x >> y;
    int c = -1;
    for (int i = 0; i < n; i++) {
        if (dt[i].judge(x, y)) {
            c = i + 1;
        }
    }
    cout << c << endl;
    return 0;
}
