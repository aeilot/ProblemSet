#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int f[5001][5001];
char str[5010];

int main() {
    // Type your code here
    scanf("%s", str + 1);
    int sz = strlen(str + 1);
    for (int i = 1; i <= sz; i++) {
        f[i][i] = 1;
        for (int j = i - 1, k = i + 1; k <= sz && j >= 1 && str[k] == str[j];
             k++, j--) {
            f[j][k]++;
        }
        for (int j = i, k = i + 1; k <= sz && j >= 1 && str[k] == str[j];
             k++, j--) {
            f[j][k]++;
        }
    }
    for (int i = 1; i <= sz; i++) {
        for (int j = 1; j <= sz; j++) {
            f[i][j] = f[i][j] - f[i - 1][j - 1] + f[i - 1][j] + f[i][j - 1];
        }
    }
    int T;
    scanf("%d", &T);
    while (T--) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        printf("%d\n", f[b][b] + f[a][a] - f[a][b] - f[b][a]);
    }
    return 0;
}