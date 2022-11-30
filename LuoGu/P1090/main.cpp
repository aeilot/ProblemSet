#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    // Type your code here
    long long ans = 0;
    priority_queue<long long, vector<long long>, greater<long long> > pq;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }
    while (!pq.empty()) {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        ans += a + b;
        if (!pq.empty()) pq.push(a + b);
    }
    cout << ans << endl;
    return 0;
}