#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int ar[20];
int n, k;
int flag[20];

int isPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int f(int start, int rem, int sum) {
    if (rem == 0) {
        return isPrime(sum);
    }
    int ans = 0;
    for (int i = start; i < n; i++) {
        ans += f(i + 1, rem - 1, sum + ar[i]);// 不降原则
    }
    return ans;
}

int main() {
    // Type your code here
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> ar[i];
    int ans = f(0, k, 0);
    cout << ans << endl;
    return 0;
}