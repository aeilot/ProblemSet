#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

#define MAXN 100000007;

using namespace std;

int a[1000001];
bool b[1000001];
int sift[10001];
int mem[1000001];
int cnt = 0;

void sft(int x){
    for(int i = 0; i<=x; i++) b[i] = true;
    b[0] = b[1] = false;
    int mmm = sqrt(x)+0.5;
    for(int i = 2; i<= mmm; i++){
        if(!b[i]) continue;
        for(int j = 2; j*i<=x; j++){
            b[i*j] = false;
        }
    }
    for(int i = 0; i<=x; i++){
        if(b[i]){
            sift[cnt++] = i;
            mem[i] = 0;
        }
    }
}

int main(){
    // Type your code here
    int n,m;
    cin >> n >> m;
    int mx  = 0;
    memset(mem,-1, sizeof(mem));
    for(int i = 0; i<n; i++){
        cin >> a[i];
        mx = max(mx,a[i]);
    }
    sft(mx);
    for(int i = 0; i<m; i++){
        int x,y;
        cin >> x >>y;
        int a1 = lower_bound(sift,sift+cnt, x)-sift;
        int a2 = lower_bound(sift,sift+cnt, y)-sift;
        if(sift[a2]!=y) a2--;
        long long ans = 0;
        for(int j = a1; j<=a2; j++){
            if(mem[sift[j]]==0){
                for(int k = 0; k<n; k++){
                    if(a[k]%sift[j]==0 && a[k]!=sift[j]){
                        mem[sift[j]]++;
                    }
                }
            }
            ans+=mem[sift[j]];
            ans %= MAXN;
        }
        cout << ans << endl;
    }
    return 0;
}