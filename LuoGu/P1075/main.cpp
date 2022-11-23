#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    // Type your code here
    long long n;
    cin >> n;
    int i = 2;
    while (i <= sqrt(n)) {
        if (n % i == 0) break;
        i++;
    }
    cout << n / i;
    return 0;
}