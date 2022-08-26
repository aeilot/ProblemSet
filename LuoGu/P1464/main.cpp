#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

long long MEM[25][25][25];// 记忆化搜索减少重复计算

long long w(long long a, long long b, long long c) {
    // printf("w(%lld, %lld, %lld)\n", a, b, c);
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    else if (a > 20 || b > 20 || c > 20)
        a = b = c = 20;
    if (MEM[a][b][c] != -1)
        return MEM[a][b][c];
    else if (a > 20 || b > 20 || c > 20) {
        MEM[a][b][c] = w(20, 20, 20);
    } else if (a < b && b < c)
        MEM[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    else
        MEM[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) +
                       w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    return MEM[a][b][c];
}

int main() {
    // Type your code here
    string str;
    while (1) {
        getline(cin, str);
        long long a, b, c;
        sscanf(str.c_str(), "%lld %lld %lld", &a, &b, &c);
        if (a == -1 && b == -1 && c == -1) break;
        memset(MEM, -1, sizeof(MEM));
        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, w(a, b, c));
    }
    return 0;
}