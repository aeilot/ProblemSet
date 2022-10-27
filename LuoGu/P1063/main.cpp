#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

struct Node {
    int m, r;
    long long val = 0;
} DP[210][210];

long long merge(Node &a, Node &b) { return a.m * a.r * b.r; }

int MAP[210];

int main() {
    // Type your code here
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> MAP[i];
        DP[i][i].m = MAP[i];
        DP[i - 1][i - 1].r = MAP[i];
    }
    for (int i = N + 1; i <= N * 2; i++) {
        DP[i][i].m = MAP[i - N];
        DP[i - 1][i - 1].r = MAP[i - N];
    }
    DP[2 * N][2 * N].r = DP[1][1].m;
    for (int i = 1; i <= N * 2; i++) {
        //        printf("%d: (%d, %d)\n",i,DP[i][i].m, DP[i][i].r);
    }
    for (int len = 2; len <= N; len++) {
        for (int i = 1; i + len - 1 <= 2 * N; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++) {
                long long est = merge(DP[i][k], DP[k + 1][j]);
                //                printf("EST: %lld, from %d to %d to %d\n",
                //                est,i,k,j);
                if (est + DP[i][k].val + DP[k + 1][j].val > DP[i][j].val) {
                    DP[i][j].val = est + DP[i][k].val + DP[k + 1][j].val;
                    DP[i][j].m = DP[i][k].m;
                    DP[i][j].r = DP[k + 1][j].r;
                }
            }
        }
    }
    long long mxax = 0;
    for (int i = 1; i <= N; i++) {
        mxax = max(mxax, DP[i][i + N - 1].val);
    }
    cout << mxax << endl;
    return 0;
}