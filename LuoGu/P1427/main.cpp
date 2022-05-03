#include <cstdio>
#include <iostream>

using namespace std;

int N[100];

int main() {
    // Type your code here
    int l = 0;
    while (1) {
        int tmp;
        cin >> tmp;
        if (tmp == 0) break;
        N[l++] = tmp;
    }
    for (int i = l - 1; i >= 0; i--) {
        cout << N[i] << " ";
    }
    cout << endl;
    return 0;
}