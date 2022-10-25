#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int N;
struct Trie {
    int nxt[500005][26];
    bool b[500010][110];
    int cnt;

    Trie() {
        memset(nxt, -1, sizeof(nxt));
        cnt = 0;
    }

    void insert(string &str, int num) {
        int p = 0;
        for (int i = 0; i < str.size(); i++) {
            int x = str[i] - 'a';
            if (nxt[p][x] == -1) {
                nxt[p][x] = cnt++;
            }
            p = nxt[p][x];
        }
        b[p][num] = true;
    }

    void find(string &str) {
        int p = 0;
        for (int i = 0; i < str.size(); i++) {
            int x = str[i] - 'a';
            if (nxt[p][x] == -1) {
                break;
            }
            p = nxt[p][x];
        }
        for (int i = 1; i <= N; i++) {
            if (b[p][i] == true) cout << i << " ";
        }
        cout << endl;
    }

} tt;

int main() {
    // Type your code here
    cin >> N;
    for (int i = 0; i < N; i++) {
        int L;
        cin >> L;
        string tmp, xxx;
        getline(cin, tmp);
        tmp.erase(tmp.begin());
        int p = 0;
        int tp = 0;
        for (int j = 0; j < L; j++) {
            if (p != 0) tp = p + 1;
            p = tmp.find(' ', p + 1);
            if (p == string::npos) p = tmp.size();
            xxx = tmp.substr(tp, p - tp);
            tt.insert(xxx, i + 1);
        }
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        string x;
        cin >> x;
        tt.find(x);
    }
    return 0;
}