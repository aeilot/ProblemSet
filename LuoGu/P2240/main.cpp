#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

struct gc {
    float m;
    float v;
    double priv;
};

gc makeGC(float m, float v) {
    gc re;
    re.m = m;
    re.v = v;
    re.priv = v / m;
    return re;
}

bool cmp(const gc &a, const gc &b) {
    return a.priv > b.priv;
}

gc NAR[101];
int N, T;
float sum = 0;

void solve() {
    sort(NAR, NAR + N, cmp);
    for (int i = 0; i < N; i++) {
        if (NAR[i].m <= T) {
            sum += NAR[i].v;
            T -= NAR[i].m;
        } else {
            sum += NAR[i].priv * T;
            return;
        }
    }
}

int main(int argc, char *argv[]) {
    cin >> N >> T;
    for (int i = 0; i < N; i++) {
        float m, v;
        cin >> m >> v;
        NAR[i] = makeGC(m, v);
    }
    solve();
    printf("%.2f\n", sum);
    return 0;
}
