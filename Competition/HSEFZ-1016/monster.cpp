#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int A[100001];
int KD[100001];
int JP[100001];
#define mod 1e9 + 7

unsigned A_CALC(int n, int m) {
    unsigned ans = 1;
    for (int i = n; i >= n - m + 1; i--) {
        ans *= i;
    }
    return ans;
}

int main() {
    std::ios::sync_with_stdio(0);
    // Type your code here
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    sort(A, A + n);
    //    for(int i = 0; i<n; i++) cout << A[i] << " ";
    KD[n - 1] = 0;
    JP[n - 1] = n;
    int tt = n - 1;
    for (int i = n; i >= 0; i--) {
        KD[i] = KD[i + 1] + (A[i] != A[i + 1]);
        if (A[i] == A[i + 1])
            JP[i] = JP[i + 1];
        else {
            JP[i] = i + 1;
        }
    }

    //    cout << endl;
    return 0;
}
