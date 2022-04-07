#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    // Type your code here
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << int(pow(2, n) - 1) << endl;
    }
    return 0;
}