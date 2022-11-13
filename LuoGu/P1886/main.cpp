#include <cstdio>
#include <deque>
#include <iostream>

using namespace std;

long long AR[1000010];
long long ANS[3][1000010];
int cnt = 0;

struct sr {
    int i;
    long long v;
};

int main() {
    // Type your code here
    deque<sr> mmax, mmin;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> AR[i];
    }
    for (int i = 1; i <= n; i++) {
        sr t;
        t.i = i;
        t.v = AR[i];
        while (!mmax.empty() && t.v >= mmax.back().v) {
            mmax.pop_back();
        }
        mmax.push_back(t);
        while (!mmin.empty() && t.v <= mmin.back().v) {
            mmin.pop_back();
        }
        mmin.push_back(t);
        while (!mmax.empty() && i - k + 1 > mmax.front().i) {
            mmax.pop_front();
        }
        while (!mmin.empty() && i - k + 1 > mmin.front().i) {
            mmin.pop_front();
        }
        if (i >= k) {
            ANS[0][cnt] = mmax.front().v;
            ANS[1][cnt] = mmin.front().v;
            cnt++;
        }
    }
    for (int i = 0; i < cnt; i++) {
        cout << ANS[1][i] << " ";
    }
    cout << endl;
    for (int i = 0; i < cnt; i++) {
        cout << ANS[0][i] << " ";
    }
    cout << endl;
    return 0;
}