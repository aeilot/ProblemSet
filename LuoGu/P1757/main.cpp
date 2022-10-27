#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct Obj {
    int W;
    int V;
};
int DP[1001];
vector<Obj> Groups[1001];

int main() {
    // Type your code here
    int n, m;
    cin >> m >> n;
    int ts = 0;
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        Groups[c].push_back({a, b});
        ts = max(ts, c);
    }
    DP[0] = 0;
    for (int k = 1; k <= ts; k++)
        for (int i = m; i >= 0; i--)
            for (int j = 0; j < Groups[k].size(); j++)
                if (i >= Groups[k][j].W)
                    DP[i] = max(DP[i], DP[i - Groups[k][j].W] + Groups[k][j].V);
    cout << DP[m] << endl;
    return 0;
}