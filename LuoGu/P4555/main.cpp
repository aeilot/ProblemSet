#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int p[200100];
int fr[200100];
int fl[200100];

int main() {
    // Type your code here
    string s1, s2;
    cin >> s1;
    s2.resize(s1.size() * 2 + 3);
    s2[0] = '~';
    s2[1] = '#';
    for (int i = 0, j = 2; i < s1.size(); i++, j += 2) {
        s2[j] = s1[i];
        s2[j + 1] = '#';
    }
    int ans = 0;
    for (int i = 0, l = 0, r = -1; i < s2.size(); i++) {
        int k = (i > r) ? 1 : min(p[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < s2.size() && s2[i + k] == s2[i - k]) {
            k++;
        }
        p[i] = k;
        if (i + k - 1 > r) {
            r = i + k - 1;
            l = i - k + 1;
        }
        fr[i + k - 1] = max(k - 1, fr[i + k - 1]);
        fl[i - k + 1] = max(k - 1, fl[i - k + 1]);
    }
    for (int i = 3; i < s2.size(); i += 2) {
        fl[i] = max(fl[i], fl[i - 2] - 2);
    }
    for (int i = s2.size() - 3; i >= 1; i -= 2) {
        fr[i] = max(fr[i], fr[i + 2] - 2);
    }
    for (int i = 1; i < s2.size(); i += 2) {
        if (fr[i] && fl[i]) ans = max(ans, fr[i] + fl[i]);
    }
    cout << ans << endl;
    return 0;
}