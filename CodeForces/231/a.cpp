/*
 * @Author: Louis Aeilot 
 * @Date: 2020-07-29 20:15:19 
 * @Last Modified by:   Louis Aeilot 
 * @Last Modified time: 2020-07-29 20:15:19 
 */
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int n;
    int f = 0;
    int tmpA, tmpB, tmpC;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &tmpA, &tmpB, &tmpC);
        if (tmpA + tmpB + tmpC >= 2)
            f++;
    }
    printf("%d\n", f);
    return 0;
}
