#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

long long pre[1000006];
long long cnt = 0;
bool prime[1000006];
long long num[1000006];

int main() {
    // Type your code here
    memset(prime, 1, sizeof(prime));
    memset(pre, 0, sizeof(pre));
    prime[0] = prime[1] = false;
    for (int i = 2; i <= 1000000; i++) {
        if (prime[i] == 1) {
            num[cnt++] = i;
            pre[i]++;
        }
        for (int j = 0; j < cnt && num[j] * i <= 1000000; j++) {
            prime[num[j] * i] = false;
            if (i % num[j] == 0) break;
        }
    }
    for (int i = 1; i <= 1000000; i++) {
        pre[i] += pre[i - 1];
    }
    long long n, m;
    cin >> n >> m;
    for (long long i = 0; i < n; i++) {
        long long l, r;
        cin >> l >> r;
        if (l < 1 || r > m) {
            cout << "Crossing the line" << endl;
        } else {
            cout << pre[r] - pre[l - 1] << endl;
        }
    }
    return 0;
}