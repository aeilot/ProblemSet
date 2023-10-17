#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

struct Node {
    int next, to;
} NDS[610];

int head[610];
bool vis[610];
bool dup[610][610];
bool v2[610];
int A[610], B[610];
int ind[610];
int in[610];
int cnt = 0;
map<char, int> namae_id;
map<int, char> namae;

int have = 0;

void add(int u, int v) {
    if (dup[u][v]) return;
    NDS[cnt].to = v;
    NDS[cnt].next = head[u];
    dup[u][v] = 1;
    in[v]++;
    head[u] = cnt++;
    if (!vis[u]) have++;
    if (!vis[v]) have++;
    vis[u] = 1;
    vis[v] = 1;
}

int main() {
    memset(head, -1, sizeof(head));
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        char a, b, c;
        int ida, idb;
        cin >> a >> c >> b;
        if (a == b) {
            cout << "Inconsistency found after " << i << " relations." << endl;
            return 0;
        }
        if (!namae_id[a]) {
            namae_id[a] = namae_id.size();
            ida = namae_id[a];
            namae[ida] = a;
        } else {
            ida = namae_id[a];
        }
        if (!namae_id[b]) {
            namae_id[b] = namae_id.size();
            idb = namae_id[b];
            namae[idb] = b;
        } else {
            idb = namae_id[b];
        }
        A[i] = ida;
        B[i] = idb;
    }
    for (int i = 1; i <= m; i++) {
        add(A[i], B[i]);
        for (int j = 0; j <= n; j++) {
            ind[j] = in[j];
        }
        memset(v2, 0, sizeof(v2));
        queue<pair<int, int> > qq;
        vector<char> seq;
        int ccc = 0;
        int ans = 0;
        for (int j = 1; j <= namae.size(); j++) {
            if (vis[j] && ind[j] == 0) {
                qq.push({j, 1});
                ccc++;
            }
        }
        while (!qq.empty()) {
            int x = qq.front().first;
            int v = qq.front().second;
            qq.pop();
            seq.push_back(namae[x]);
            v2[x] = 1;
            for (int j = head[x]; j != -1; j = NDS[j].next) {
                int y = NDS[j].to;
                if (v2[y]) {
                    cout << "Inconsistency found after " << i << " relations."
                         << endl;
                    return 0;
                }
                ind[y]--;
                if (ind[y] == 0) {
                    qq.push({y, v + 1});
                    ans = max(ans, v + 1);
                    ccc++;
                }
            }
        }
        if (seq.size() == n && ans == n) {
            cout << "Sorted sequence determined after " << i << " relations: ";
            for (int k = 0; k < seq.size(); k++) {
                cout << seq[k];
            }
            cout << ".";
            cout << endl;
            return 0;
        }
        if (ccc != have) {
            cout << "Inconsistency found after " << i << " relations." << endl;
            return 0;
        }
    }
    cout << "Sorted sequence cannot be determined." << endl;
    return 0;
}
