#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string AR[21];

bool cmp(const string &a, const string &b) {
    return a + b > b + a;
}

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> AR[i];
    }
    sort(AR, AR + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << AR[i];
    }
    cout << endl;
    return 0;
}
