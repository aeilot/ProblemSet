#include <cstdio>
#include <iostream>

using namespace std;

int N[10];

int main() {
    // Type your code here
    for (int i = 0; i < 10; i++) cin >> N[i];
    int h;
    cin >> h;
    h += 30;
    int c = 0;
    for (int i = 0; i < 10; i++) {
        if (N[i] <= h) c++;
    }
    cout << c << endl;
    return 0;
}