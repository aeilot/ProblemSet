#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

vector<char> seq;
int n, m, k;
bool checkSeq() {
    for (int i = 1; i < n + m; i++) {
        for (int j = 0; j + i < n + m; j++) {
            int bw = 0;
            int ww = 0;
            for (int k = j; k < j + i; k++) {
                if (seq[k] == 'b') bw++;
                if (seq[k] == 'w') ww++;
            }
            if (abs(bw - ww) > k) return false;
        }
    }
    return true;
}
int dfs(int wr, int br) {
    if (wr == 0 && br == 0) {
        if (checkSeq())
            return 1;
        else
            return 0;
    }
    long long ans = 0;
    if (wr != 0) {
        seq.push_back('w');
        ans += dfs(wr - 1, br) % 1000000007;
        seq.pop_back();
    }
    if (br != 0) {
        seq.push_back('b');
        ans += dfs(wr, br - 1) % 1000000007;
        seq.pop_back();
    }
    return ans % 1000000007;
}

int main() {
    // Type your code here
    cin >> n >> m >> k;
    if (abs(n - m) > k)
        cout << 0 << endl;
    else {
        cout << dfs(n, m) << endl;
    }
    return 0;
}