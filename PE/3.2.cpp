#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    // Type your code here
    long long m = 600851475143;
    long long k = 2;
    while (m > 1) {
        if (m % k == 0) {
            m /= k;
        } else
            k++;
    }
    cout << k << endl;
    return 0;
}