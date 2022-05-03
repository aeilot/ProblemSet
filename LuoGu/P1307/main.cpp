#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

int N[10];

int main() {
    // Type your code here
    int n;
    cin >> n;
    int flag = 1;
    if (n == 0) {
        cout << "0" << endl;
    } else {
        if (n < 0) {
            flag = -1;
            n *= -1;
        }
        int tmp = n;
        int bit = 0;
        int b;
        while (tmp > 0) {
            b = tmp - (tmp / 10) * 10;
            N[bit++] = b;
            tmp /= 10;
        }
        int ans = 0;
        int j = bit - 1;
        for (int i = 0; i < bit; i++) {
            ans += N[i] * pow(10, (j--));
        }
        ans *= flag;
        cout << ans << endl;
    }
    return 0;
}