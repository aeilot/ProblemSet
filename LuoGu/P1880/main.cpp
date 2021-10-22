#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

#define MAX_N 101
#define MAX_ND 201

//#define DEBUG

//#undef DEBUG


int MAP[MAX_ND];
int ND[MAX_ND];
int DP1[MAX_ND][MAX_ND]; // Min
int DP2[MAX_ND][MAX_ND]; // Max

int getD(int i, int j){
    return ND[j] - ND[i] + MAP[i];
}

signed main(){
    //ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> MAP[i];
        MAP[i+n] = MAP[i];
        DP1[i][i] = DP2[i][i] = DP1[i+n][i+n] = DP2[i+n][i+n] = MAP[i];
    }
    for(int i = 1; i<= n*2; i++) ND[i] = ND[i-1] + MAP[i];
    for(int i = 1; i<=n*2-1; i++){
        DP1[i][i+1] = DP2[i][i+1] = getD(i,i+1);
    }
    for(int len = 3; len<=n; len++){
        for(int i = 1; i+len-1<=n*2; i++){
            int j = i+len-1;
            int mmin = INT_MAX;
            int mmax = 0;
            for(int k = i; k<j; k++){
                int tmmin = DP1[i][k] + DP1[k+1][j] + getD(i,k) + getD(k+1,j);
                int tmmax = DP2[i][k] + DP2[k+1][j]+ getD(i,k) + getD(k+1,j);
                if(i==k){ tmmin -= DP1[i][k]; tmmax -= DP2[i][k];}
                if(j==k+1){ tmmin -= DP1[k+1][j]; tmmax -= DP2[k+1][j];}
                mmin = min(tmmin, mmin);
                mmax = max(tmmax, mmax);
#ifdef DEBUG
                cout << i << " " << j << " " << k << " " << mmin << " " << mmax << endl;
#endif
            }
            DP1[i][j] = mmin;
            DP2[i][j] = mmax;
#ifdef DEBUG
                cout << "REFRESHED WITH MIN: " << mmin << " AND MAX: " << mmax << endl;
#endif
        }
    }
    int ans1 = INT_MAX, ans2 = 0;
    for(int i = 1; i<=n; i++){
        ans1 = min(ans1, DP1[i][i+n-1]);
        ans2 = max(ans2, DP2[i][i+n-1]);
    }
    cout << ans1 << endl << ans2 << endl;
    return 0;
}

