#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    // Type your code here
    int n;
    cin >> n;
    int cc = 1;
    int swap = 0;
    int upper = 1;
    int lower = 1;
    if (n == 1)
        cout << "1/1" << endl;
    else
        while (1) {
            cc++;
            if (swap == 0) {
                swap = 1;
                lower++;
                while (cc < n && lower > 1) {
                    lower--;
                    upper++;
                    cc++;
                }
                if (cc == n) {
                    cout << upper << "/" << lower << endl;
                    return 0;
                }
            } else {
                swap = 0;
                upper++;
                while (cc < n && upper > 1) {
                    lower++;
                    upper--;
                    cc++;
                }
                if (cc == n) {
                    cout << upper << "/" << lower << endl;
                    return 0;
                }
            }
        }
    return 0;
}