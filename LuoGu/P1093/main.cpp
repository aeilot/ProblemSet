#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

struct Score {
    int no;
    int ch;
    int ma;
    int en;
};

Score AR[301];

Score make_score(int no, int a, int b, int c) {
    Score ra;
    ra.no = no;
    ra.ch = a;
    ra.ma = b;
    ra.en = c;
    return ra;
}

bool cmp(const Score &a, const Score &b) {
    int suma = a.ch + a.ma + a.en;
    int sumb = b.ch + b.ma + b.en;
    if (suma != sumb) return suma > sumb;
    else if (a.ch != b.ch)
        return a.ch > b.ch;
    return a.no < b.no;
}

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        AR[i] = make_score(i + 1, a, b, c);
    }
    sort(AR, AR + n, cmp);
    for (int i = 0; i < 5; i++) {
        int sum = AR[i].ch + AR[i].ma + AR[i].en;
        cout << AR[i].no << " " << sum << endl;
    }
    return 0;
}
