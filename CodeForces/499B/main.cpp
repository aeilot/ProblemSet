#include <iostream>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

int main(){
    map<string,string> dict;
    int n,m;
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        string ta,tb;
        cin >> ta >> tb;
        if(tb.size()<ta.size()){
            dict.insert({ta,tb});
        }else{
            dict.insert({ta,ta});
        }
    }
    for(int i = 0; i<n; i++){
        string ta;
        cin >> ta;
        cout << dict[ta] << " ";
    }
    cout << endl;
    return 0;
}