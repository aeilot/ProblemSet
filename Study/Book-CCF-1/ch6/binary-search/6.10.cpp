#include <cstdio>
#include <iostream>

using namespace std;

int Ns[10000];

int main(int argc, char *argv[]) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> Ns[i];
    Ns[0] = -1;
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        int lt = 1, rt = n, mid;
        while (lt <= rt) {
            mid = (lt + rt) / 2;
            if (Ns[mid] > t) {
                rt = mid - 1;
            } else {
                lt = mid + 1;
            }
        }
        cout << Ns[rt] << endl;
    }
    return 0;
}

