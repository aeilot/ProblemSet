#include <stdio.h>
#include <iostream>

using namespace std;

#define MAX_N 1001

int SPc[MAX_N][MAX_N];

int main(){
    for(int i = 0; i< MAX_N; i++){
        for(int j = 0; j< MAX_N; j++){
            SPc[i][j]=0;
        }
    }
    int n;
    cin >> n;
    for(int i = 0; i<n ; i++){
        int a,b,g,k;
        cin >> a >> b >> g >> k;
        for(int i = a; i<= a+g; i++){
            for(int j = b; j<= b+k; j++){
                SPc[i][j]++;
            }
        }
    }
    int x, y;
    cin >> x >> y;
    if(x<0 || y <0){
        cout << -1 << endl;
    }
    if(SPc[x][y]==0){
        cout << -1 << endl;
    }
    cout << SPc[x][y] << endl;
    return 0;
}
