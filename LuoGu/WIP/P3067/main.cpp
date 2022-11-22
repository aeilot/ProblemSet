#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int A[21];
long long sum = 0;

//void dfs(int l, int r, long long sm, long long smb[], long long& cntb){
//    if(sm>sum) return;
//    if(l>r){
//        smb[cntb++] = sm;
//         return;
//    }
//    dfs(l+1,r,sm+A[l],smb,cntb);
//    dfs(l+1,r,sm,smb,cntb);
//}
int n;
long long ans = 0;

void dfs(int dep, long long sm1, long long sm2) {
    if (dep == n + 1) {
        if (sm1 == sm2 && sm1 != 0) ans++;
        return;
    }
    dfs(dep + 1, sm1 + A[dep], sm2);
    dfs(dep + 1, sm1, sm2);
    dfs(dep + 1, sm1, sm2 + A[dep]);
}

int main() {
    // Type your code here
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        sum += A[i];
    }
    dfs(1, 0, 0);
    cout << ans << endl;
//        int mid = n/2;
//        long long ans = 0;
//        long long sma[10001], cna=0, smb[10001], cnb=0;
//        dfs(1,mid,0,sma,cna);
//        dfs(mid+1,n,0,smb,cnb);
//        sort(sma+1,sma+cna+1);
//        for(int i = 0;i<cnb; i++){
//            long long smt = sum - smb[i];
//            int l = 0,r = cna;
//            int mid;
//            while(l<=r){
//                mid = (l+r)/2;
//                if(sma[mid]>smt){
//                    r = mid-1;
//                }else{
//                    l = mid+1;
//                }
//            }
//            ans += (upper_bound(sma+1, sma+1+cna, smt) - sma -1) -l;
//        }
//        cout << ans << endl;
    return 0;
}