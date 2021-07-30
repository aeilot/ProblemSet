#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    if (n % 2 != 0) cout << -1 << endl;
    else {
        int ar[5000000];
        for (int i = 0; i < 5000000; i++) ar[i] = 0;
        int count = 0;
        while (n != 0) {
            n /= 2;
            int tmp = n % 2;
            ar[count++] = tmp;
        }
        for (int i = count - 1; i >= 0; i--) {
            if (ar[i] == 0) continue;
            double tmp2 = pow(2, i + 1);
            printf("%.0f ", tmp2);
        }
        printf("\n");
    }
    return 0;
}
