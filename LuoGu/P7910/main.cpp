#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    // Type your code here
    long long n,L,R;
    cin >> n >> L >> R;
    if(L/n != R/n){
        cout << n-1 << endl;
    }else{
        cout << R%n << endl;
    }
    return 0;
}