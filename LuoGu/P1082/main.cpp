#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

void exgcd(int a, int b, int &x, int &y){
    if(!b){
        x = 1;
        y = 0;
        return;
    }
    exgcd(b,a%b,y,x);
    y -= (a/b)*x;
}

int main(){
    int a,b;
    cin >> a >> b;
    int x,y;
    exgcd(a,b,x,y);
    x = (x+b)%b;
    cout << x << endl;
    return 0;
}
