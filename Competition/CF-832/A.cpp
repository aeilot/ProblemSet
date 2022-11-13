#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    // Type your code here
    int t;
    cin >> t;
    long long sum1 = 0, sum2 = 0;
    long long tmp;
    while (t--) {
        sum1 = sum2 = 0;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            if (tmp > 0) {
                sum1 += tmp;
            } else if (tmp < 0) {
                sum2 += tmp;
            }
        }
        sum2 = abs(sum2);
        cout << abs(sum1 - sum2) << endl;
    }
    return 0;
}
