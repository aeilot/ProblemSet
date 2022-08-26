#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

int mon[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    // Type your code here
    int a1, b1;
    int ans = 0;
    scanf("%d %d", &a1, &b1);
    for (int i = 1; i <= 12; i++) {
        for (int j = 1; j <= mon[i]; j++) {
            int a = i / 10;
            int b = i % 10;
            int c = j / 10;
            int d = j % 10;
            if (d == 0) continue;
            int num = d * 10000001 + c * 1000010 + b * 100100 + a * 11000;
            // printf("%d\n", num);
            if (num < a1 || num > b1) continue;
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}