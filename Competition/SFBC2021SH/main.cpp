#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int answerFunc1(int n) {
    int res = 0;  // res为结果变量
    //在本函数体内输入解题代码
    res = 4 * pow(n, 0) + 3 * pow(n, 1) + 2 * pow(n, 2) + 1 * pow(n, 3);
    return res;
}

int answerFunc2(int n) {
    int res = 0;  // res为结果变量
    //在本函数体内输入解题代码
    int AR[7] = {6, 0, 1, 2, 3, 4, 5};
    int offset = int(pow(10, n) - 1) % 7;
    res = AR[offset];
    return res;
}

int decom(int n) {
    int max = n;
    for (int i = 1; i <= n / 2; i++) {
        int a = i;
        int b = n - i;
        int ta = decom(a);
        int tb = decom(b);
        if (ta * tb > max) max = ta * tb;
    }
    return max;
}

int answerFunc3(int n) {
    int res = 0;  // res为结果变量
    //在本函数体内输入解题代码
    res = decom(n);
    if (res == n) {
        int a = n / 2;
        int b = n - a;
        res = a * b;
    }
    return res;
}

int answerFunc4() {
    int res = 0;  // res为结果变量
    //在本函数体内输入解题代码
    res = 5;
    return res;
}

int answerFunc5(int n) {
    int res = 0;  // res为结果变量
    //在本函数体内输入解题代码
    int t = 3;
    while (t != n) {
        if (t * t > n) {
            t++;
        } else {
            t *= t;
        }
        res++;
    }
    return res;
}

int answerFunc6(int n) {
    int res = 0;  // res为结果变量
    //在本函数体内输入解题代码
    int upper = 1;
    int lower = 1;
    for (int i = 0; i < n - 1; i++) {
        upper *= 9 - i;
    }
    for (int i = 0; i < n - 1; i++) {
        lower *= n - 1 - i;
    }
    res = upper / lower;
    return res;
}

int main() {
    cout << answerFunc1(15) << endl;
    return 0;
}