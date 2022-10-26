#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int st[310];

int main(){
    // Type your code here
    int n;
    cin >> n;
    long long ans = 0;
    for(int i = 1; i<=n ;i++){
        cin >> st[i];
    }
    st[0] = 0;
    sort(st,st+n+1);
    int now = 0, j = n;
    int mk = 0;
    for(int k = 0; k<n; k++, mk^=1){
        ans += (st[now]-st[j]) * (st[now]-st[j]);
        int t = now;
        now = j;
        j = mk == 0 ? t+1: t-1;
    }
    cout << ans << endl;
    return 0;
}