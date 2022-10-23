#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, c = 0;
int tmp[100001];

vector<int> G[100001];
struct Node {
    int val, indeg;
    vector<Node> subNodes;

    friend bool operator<(const Node& a, const Node& b) {
        if (a.indeg == b.indeg)
            return a.val > b.val;
        else
            return a.indeg < b.indeg;
    }
} nd[100001];

void bfs() {
    priority_queue<Node> pq;
    for (int i = 1; i <= n; i++) {
        if (nd[i].indeg == 0) {
            pq.push(nd[i]);
        }
    }
    while (!pq.empty()) {
        Node t = pq.top();
        tmp[c++] = t.val;
        // cout << t.val << endl;
        pq.pop();
        for (auto i : G[t.val]) {
            nd[i].indeg--;
            if (nd[i].indeg == 0) {
                pq.push(nd[i]);
            }
        }
    }
    if (c != n)
        cout << -1 << endl;
    else {
        for (int i = 0; i < c; i++) {
            cout << tmp[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Type your code here
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        nd[i].val = i;
        nd[i].indeg = 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        nd[b].indeg++;
        G[a].push_back(b);
    }
    bfs();
    return 0;
}