#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

#define MOD 19940417

long long qpow(long long a, long long b){
    long long ans = 1;
    for(;b;b>>=1){
        if(b&1) ans = ans*a % MOD;
        a = a*a % MOD;
    }
    return ans;
}

struct Point{
    int x,y;

    const bool operator==(const Point m) const{
        return x==m.x && y==m.y;
    }
}PTS[1000010];

bool cmp(Point &a, Point &b){
    return a.x < b.x;
}

int dp[1000010][2];

int main(){
    // Type your code here
    int n,k;
    cin >> n >> k;
    for(int i = 1; i<=k; i++){
        int a,b;
        cin >> a >> b;
        PTS[i].x = a;
        PTS[i].y = b;
    }
    PTS[k+1].x = n;
    PTS[k+1].y = 0;
    k = unique(PTS,PTS+k+2) - PTS -1;
    sort(PTS,PTS+k+2,cmp);
    int tmax = 0;
    cout << k << endl;
    dp[0][0] = 1; // 0 UP 1 DOWN
    for(int i = 1; i<=k; i++){
        int x1 = PTS[i-1].x, x2 = PTS[i].x, y1 = PTS[i-1].y, y2 = PTS[i-1].y;
        int len = x2-x1-y1-y2;
        tmax = max(tmax, x2-x1+y1+y2);
        if(x2-x1==y2-y1){
            dp[i][1] += dp[i-1][1] % MOD;
            if(y1==0) dp[i][1] = (dp[i][1] + dp[i-1][0]) % MOD;
        }else if(x2-x1==y1-y2){
            dp[i][0] = (dp[i][0] + dp[i-1][0]+dp[i-1][1]) % MOD;
        }else if(len<0){
            dp[i][0] += dp[i-1][1] % MOD;
            if(y1==0) dp[i][0] = (dp[i][0] + dp[i-1][0]) % MOD;
        }else if(len>0){
            long long t = (2*dp[i-1][1]+dp[i-1][0]) * qpow(2,len/2 -1) %MOD;
            dp[i][0] += t;
            if(y2>0) dp[i][1] += t;
        }else{
            dp[i][0] = (dp[i][0]+dp[i-1][1]) % MOD;
            if(y1==0) dp[i][0] =  (dp[i][0]+dp[i-1][0]) % MOD;
            dp[i][1] = (dp[i][1]+dp[i-1][1] + dp[i-1][0]) % MOD;
        }
    }
    cout << dp[k][0] << " " << tmax  << endl;
    return 0;
}