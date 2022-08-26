#include <iostream>
using namespace std;

int main() {
    int a = 1, b = 2, c = a + b;
    int sum = 2;
    while (c <= 4000000) {
        if (c % 2 == 0) sum += c;
        a = b;
        b = c;
        c = a + b;
        printf("%d %d %d %d\n", a, b, c, sum);
    }
    printf("%d\n", sum);
    return 0;
}