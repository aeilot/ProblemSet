#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

int D[601];

int main(int argc, char *argv[]) {
    int n, w;
    cin >> n >> w;
    for (int i = 0; i < 601; i++) D[i] = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        D[tmp]++;
        int count = max(1.00, floor((i + 1) * w * 0.01));
        int minv = 1000;
        for (int i = 600; i >= 0; i--) {
            if (count <= 0) break;
            if (D[i] > 0) {
                minv = min(i, minv);
                count -= D[i];
            }
        }
        cout << minv << " ";
    }
    cout << endl;
    return 0;
}
