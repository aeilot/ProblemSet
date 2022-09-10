#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[100];
int dp1[100];
int dp2[100];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >>a[i];
        dp1[i] = dp2[i] = 1;
    }
    for(int i = 1; i<n; i++){
        for(int j = 0; j<i; j++){
            if(a[j]<a[i] && dp1[j]+1 >= dp1[i]){
                dp1[i] = dp1[j]+1;
            }
        }
    }
    for(int i = n-2; i>=0; i--){
        for(int j = i+1; j<n; j++){
            if(a[j]<a[i] && dp2[j]+1 >= dp2[i]){
                dp2[i] = dp2[j]+1;
            }
        }
    }
    int ans = -100;
    for(int i = 0; i<n; i++){
        ans = max(ans, dp1[i]+dp2[i]-1);
        // cout << dp1[i] << " " << dp2[i] << endl;
    }
    cout << n-ans << endl;
    return 0;
}