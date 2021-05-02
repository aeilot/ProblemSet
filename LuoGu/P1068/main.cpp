#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;

struct Com {
    int k;
    int s;
};

Com makeCom(int k, int s) {
    Com ra;
    ra.k = k;
    ra.s = s;
    return ra;
}

bool cmp(const Com &a, const Com &b) {
    if (a.s != b.s) return a.s > b.s;
    return a.k < b.k;
}

Com AR[10000];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int k, s;
        cin >> k >> s;
        AR[i] = makeCom(k, s);
    }
    sort(AR, AR + n, cmp);
    int scLine = AR[int(m * 1.5) - 1].s;
    int i = 0;
    for (; i < n;) {
        if (AR[i].s < scLine) break;
        else {
            i += 1;
        }
    }
    cout << scLine << " " << i << endl;
    for (int j = 0; j < i; j++) {
        cout << AR[j].k << " " << AR[j].s << endl;
    }
    return 0;
}