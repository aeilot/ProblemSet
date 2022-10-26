#include <iostream>
#include <cstdio>
#include <climits>
#include <cstring>

using namespace std;

long long W[200010], V[200010];
long long L[200010], R[200010];
long long prew[200010];
long long prevv[200010];
long long n,m;
long long s;
long long t = LLONG_MAX;

bool judge(long long x){
    long long Y = 0;
    prew[0] = prevv[0] = 0;
    for(long long i = 1;i<=n; i++){
        if(W[i]>=x){
            prew[i] = prew[i-1] + 1;
            prevv[i] = prevv[i-1] +V[i];
        }
        else{
            prew[i] = prew[i-1];
            prevv[i] = prevv[i-1];
        }
    }
    for(long long i = 1; i<=m; i++){
        Y +=(prew[R[i]] - prew[L[i]-1])*(prevv[R[i]] - prevv[L[i]-1]);
    }
    t = abs(s - Y);
    return Y > s;
}

int main(){
    // Type your code here
    memset(prew,0,sizeof(prew));
    memset(prevv,0,sizeof(prevv));
    cin >> n >> m >> s;
    long long mw = 0;
    for(long long i = 1; i<=n; i++){
        cin >> W[i] >> V[i];
        mw = max(mw,W[i]);
    }
    for(long long i=1; i<=m; i++){
        cin >> L[i] >> R[i];
    }
    long long l = 0,r=mw;
    long long mid = l +((r-l)>>1);
    long long ans = LLONG_MAX;
    while(l<=r){
        mid = l + ((r-l)>>1);
        if(judge(mid)){
            l = mid+1;
        }else{
            r = mid-1;
        }
        ans = min(ans,t);
    }
    ans = min(ans,t);
    cout << ans << endl;
    return 0;
}