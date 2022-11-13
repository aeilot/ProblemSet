#include <cstdio>
#include <deque>
#include <iostream>

using namespace std;

int EFF[100010];
long long DP[100010];
long long PRE[100010];

struct sd {
    int i;
    long long v;
};

deque<sd> mDP;

int main() {
    // Type your code here
    int n, k;
    cin >> n >> k;
    PRE[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> EFF[i];
        PRE[i] = EFF[i] + PRE[i - 1];
    }
    DP[0] = 0;
    for (int i = 1; i <= n; i++) {
        sd t;
        t.i = i;
        t.v = DP[i - 1] - PRE[i];
        while (!mDP.empty() && t.v > mDP.back().v) {
            mDP.pop_back();
        }
        mDP.push_back(t);
        while (!mDP.empty() && i - k > mDP.front().i) {
            mDP.pop_front();
        }
        if (i - k >= 1)  // CAUTION
            DP[i] = PRE[i] + mDP.front().v;
        else
            DP[i] = PRE[i];
    }
    cout << DP[n] << endl;
    return 0;
}