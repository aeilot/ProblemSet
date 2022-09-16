#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    long long m, s, t;
    cin >> m >> s >> t;
    long long savs = s;
    int i;
    for (i = t; i > 0; i--) {
        if (s <= 0) {
            cout << "Yes" << endl
                 << t - i << endl;
            return 0;
        }
        if (m >= 10) {
            m -= 10;
            s -= 60;
        } else {
            int dt = ceil((10 - m) / 4.0);
            int v1 = 60;
            int v2 = 17 * dt;
            if (dt >= i) {
                int c = i;
                while (s > 0 && c > 0) {
                    s -= 17;
                    c--;
                }
                if (s <= 0) {
                    cout << "Yes" << endl
                         << t - c << endl;
                } else {
                    while (c > 0) {
                        s -= 17;
                        c--;
                    }
                    cout << "No" << endl
                         << savs - s << endl;
                }
                return 0;
            } else if (v2 > v1 || (v1 >= v2 && v2 >= s)) {
                while (dt > 0 && i > 0) {
                    s -= 17;
                    if (s <= 0) {
                        cout << "Yes" << endl
                             << t - i << endl;
                        return 0;
                    }
                    dt--;
                    i--;
                }
            } else if (v1 >= v2) {
                i -= dt;
                s -= 60;
                m += dt * 4;
                m -= 10;
            }
        }
    }
    if (s <= 0) {
        cout << "Yes" << endl
             << t - i << endl;
    } else
        cout << "No" << endl
             << savs - s << endl;
    return 0;
}