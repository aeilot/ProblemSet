#include <cstdio>
#include <iostream>

using namespace std;

int AR[1000001];

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void qSort(int L, int R) {
    int i = L, j = R, t = (L + R) / 2;
    int mid = AR[t];
    while (i <= j) {
        while (AR[i] < mid) i++;
        while (AR[j] > mid) j--;
        if (i <= j) {
            swap(AR[i], AR[j]);
            i++;
            j--;
        }
    }
    if (j > L) qSort(L, j);
    if (i < R) qSort(i, R);
}

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> AR[i];
    }
    qSort(1, n);
    for (int i = 1; i <= n; i++) cout << AR[i] << " ";
    cout << endl;
    return 0;
}
