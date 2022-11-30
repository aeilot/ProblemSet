#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int p[110000001];

int main() {
    // Type your code here
    string s1;
    cin >> s1;
    string s2;
    s2.resize(s1.size() * 2 + 4);
    s2[0] = '~';
    s2[1] = '#';
    for (int i = 0, j = 2; i < s1.size(); i++, j += 2) {
        s2[j] = s1[i];
        s2[j + 1] = '#';
    }
    int ans = 0;
    for (int i = 0, l = 0, r = -1; i < s2.size(); i++) {
        int k = (i > r) ? 1 : min(p[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < s2.size() && s2[i - k] == s2[i + k]) {
            k++;
        }
        p[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
        ans = max(ans, p[i]);
    }
    cout << ans - 1 << endl;
    return 0;
}