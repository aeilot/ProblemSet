#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int MAP[50010];
int L, N, M;

bool check(int mid) {
    int num = 0;
    int lst = MAP[0];
    for (int i = 1; i <= N + 1; i++) {
        if (abs(MAP[i] - lst) < mid) {
            num++;
        } else {
            lst = MAP[i];
        }
    }
    return num <= M;
}

int main() {
    // Type your code here
    cin >> L >> N >> M;
    int r = L, l = 0;
    MAP[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> MAP[i];
    }
    MAP[N + 1] = L;
    sort(MAP, MAP + 1 + N);
    for (int i = 1; i <= N + 1; i++) {
        l = min(abs(MAP[i] - MAP[i - 1]), l);
    }
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << r << endl;
    return 0;
}