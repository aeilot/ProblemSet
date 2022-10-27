#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    long long n,m;
    cin >> n >> m;
    long long i;
    for(i = 1; i<=m; i++){
        n++;
        if(n%3==0) n/=3;
        if(n==2) break;
    }
    if(i>=m){
        cout << n << endl;
    }else if((m-i) % 2 ==1){
        cout << 1 << endl;
    }else{
        cout << 2 << endl;
    }
    return 0;
}