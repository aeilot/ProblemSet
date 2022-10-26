#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    long long t;
    cin >> t;
    for (long long i = 0; i < t; i++) {
        long long n, k, s;
        cin >> n >> k >> s;
        long long M = (1 + k) * k / 2;
        long long MM = (2 * n + 1 - k) * k / 2;
        if (s > MM || s < M)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}