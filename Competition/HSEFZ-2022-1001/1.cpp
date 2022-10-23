#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>

using namespace std;

int ar[500001];
int cnt = 0;
int list[500001];
int n, k;

int getNext(int x) {
    if (x + k + 1 < n) return x + k + 1;
    return x + k + 1 - n;
}

int main() {
    // Type your code here
    cin >> n >> k;
    k += 1;
    long long avg = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        avg += tmp;
        ar[i] = tmp;
    }
    avg /= n;
    long long ans = 0;
    if (n % k == 0) {
        for (int i = 0; i < k; i++) {
            cnt = 0;
            for (int j = i; j < n; j += k) {
                list[cnt++] = avg - ar[j];
            }
            for (int j = 0; j < cnt; j++) {
                if (list[j] > 0) {
                    ans += list[j];
                }
            }
        }
    } else {
        for (int j = 0; j != 0; j = getNext(j)) {
            list[cnt++] = avg - ar[j];
        }
        for (int j = 0; j < cnt; j++) {
            if (list[j] > 0) {
                ans += list[j];
            }
        }
    }
    cout << ans << endl;
    return 0;
}