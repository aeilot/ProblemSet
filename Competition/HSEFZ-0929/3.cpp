#include <climits>
#include <cstdio>
#include <iostream>

using namespace std;

long long power(long long a) {
    long long ans = 0;
    while (a > 0) {
        long long t = a / 10;
        t *= 10;
        ans += a - t;
        a /= 10;
    }
    return ans;
}

int main() {
    // Type your code here
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        long long n, k;
        cin >> n >> k;
        long long min9 = n;
        int cj = 0;
        for (int j = 0; j <= 8; j++) {
            long long t = n + j * k;
            if (t % 9 != 0)
                t %= 9;
            else if (t == 0)
                t = 0;
            else if (t % 9 == 0)
                t = 9;
            if (t < min9) {
                min9 = t;
                cj = j;
            }
        }
        n = n + cj * k;
        long long ex = n % 9;
        if (n == 0)
            ex = 0;
        else if (n % 9 == 0)
            ex = 9;
        long long tn = n;
        for (int j = 0; j <= 3; j++) {
            if (j > 0) tn = power(tn);
            if (tn == ex) {
                cj += j;
                break;
            }
        }
        cout << ex << " " << cj << endl;
    }
    return 0;
}