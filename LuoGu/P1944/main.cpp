#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int DP[1000001];
char str[1000001];
int main() {
    // Type your code here
    cin >> (str + 1);
    int ans = 0, id;
    int l = strlen(str + 1);
    for (int i = 2; i <= l; i++) {
        if ((str[i] == ']' && str[i - DP[i - 1] - 1] == '[') ||
            (str[i] == ')' && str[i - DP[i - 1] - 1] == '(')) {
            DP[i] = 2 + DP[i - 1] + DP[i - DP[i - 1] - 2];
            if (DP[i] > ans) {
                ans = DP[i];
                id = i;
            }
        } else {
            DP[i] = 0;
        }
    }
    for (int j = id - ans + 1; j <= id; j++) {
        cout << str[j];
    }
    cout << endl;
    return 0;
}