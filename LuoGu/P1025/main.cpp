#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
// int sav[7][201];
int div(int remain, int sum, int last) {
    if (remain == 0 && sum == 0) {
        return 1;
    } else if (remain == 0 && sum > 0) {
        return 0;
    }  // 剪枝
    int ans = 0;
    for (int i = last; i <= sum; i++) {
        // if (sav[remain - 1][sum - i] != -1)
        //     ans += sav[remain - 1][sum - i];
        // else {
        //     sav[remain - 1][sum - i] = div(remain - 1, sum - i, i);
        //     ans += sav[remain - 1][sum - i];
        // }
        if (i == 0) continue;
        ans += div(remain - 1, sum - i, i);
    }
    return ans;
}

int main() {
    // Type your code here
    // memset(sav, -1, sizeof(sav));
    int n, k;
    cin >> n >> k;
    int ans = div(k, n, 0);
    cout << ans << endl;
    return 0;
}