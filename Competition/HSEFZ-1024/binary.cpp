#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int map[501];

int main() {
    // Type your code here
    memset(map,0,sizeof(map));
    string S, T;
    string tmp;
    cin >> S >> T;
    tmp = T;
    /*
     * 0101101
     * 0101010
     */
    while(T[0]==T[T.size()-1]){
        T = T.substr(0,T.size()-1);
    }
    for(int i = 0; i<=S.size()/T.size()+0.5; i++){
        T+=T;
    }
    int op = 0;
    for(int i = 0; i<S.size();i++){
        if(T[i]==S[i]) {
            map[i] = -2;
        }else{
            if(i-1>=0 && map[i-1]!=-2 && S[i-1]==T[i]){
                if(map[i-1]!=2) op++;
                map[i] = 2;
                swap(S[i-1],S[i]);
            }else if(i+1<S.size() && map[i-1]!=-2 && S[i+1]==T[i]){
                if(map[i+1]!=2) op++;
                map[i] = 2;
                swap(S[i+1],S[i]);
            }
        }
    }
    int pos = 0;
    int count = 0;
    while((pos = S.find(tmp,pos))!=string::npos){
        count ++;
    }
    cout << count << " " << op << endl;
    return 0;
}