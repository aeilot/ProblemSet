#include <cstdio>
#include <deque>
#include <iostream>

using namespace std;

int AR[2000010];
int ANS[2000010];

struct sd {
    int i, v;
};

int main() {
    // Type your code here
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    deque<sd> mmax;
    for (int i = 1; i <= n; i++) cin >> AR[i];
    for (int i = 1; i <= n; i++) {
        sd t;
        t.i = i;
        t.v = AR[i];
        while (!mmax.empty() && t.v >= mmax.back().v) {
            mmax.pop_back();
        }
        mmax.push_back(t);
        while (!mmax.empty() && i - k + 1 > mmax.front().i) {
            mmax.pop_front();
        }
        if (i >= k) {
            ANS[cnt] = mmax.front().v;
            cnt++;
        }
    }
    for (int i = 0; i < cnt; i++) {
        cout << ANS[i] << endl;
    }
    return 0;
}