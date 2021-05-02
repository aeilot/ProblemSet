#include <iostream>

using namespace std;

int BK[1001] = {0};

int main() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (BK[tmp] == 0) sum++;
        BK[tmp]++;
    }
    cout << sum << endl;
    for (int i = 0; i < 1001; i++) {
        if (BK[i] > 0) cout << i << ' ';
    }
    cout << endl;
    return 0;
}