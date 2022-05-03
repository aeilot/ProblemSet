#include <cstdio>
#include <iostream>

using namespace std;
int N[101];
int Flag[20005];
int main() {
    // Type your code here
    int c;
    cin >> c;
    for (int i = 0; i < 20005; i++) {
        Flag[i] = -1;
    }
    for (int i = 0; i < c; i++) {
        cin >> N[i];
        Flag[N[i]] = 0;
    }
    for (int i = 0; i < c; i++) {
        for (int j = i + 1; j < c; j++) {
            if (Flag[N[i] + N[j]] == 0) Flag[N[i] + N[j]] = 1;
        }
    }
    int cc = 0;
    for (int i = 0; i < 20005; i++) {
        if (Flag[i] == 1) cc++;
    }
    cout << cc << endl;
    return 0;
}