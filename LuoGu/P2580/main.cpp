#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

struct Trie{
    int nex[500001][26];
    int cnt = 0;
    bool ex[500001];
    int count[500001];

    Trie(){
        memset(count,0,sizeof(count));
    }

    void insert(char* str){
        int len = strlen(str);
        int p = 1;
        for(int i = 0; i<len; i++){
            int ch = str[i] - 'a';
            if(!nex[p][ch]) nex[p][ch] = ++cnt;
            p = nex[p][ch];
        }
        ex[p] = true;
    }

    int search(char* str){
        int len = strlen(str);
        int p = 1;
        for(int i = 0; i<len; i++){
            int ch = str[i] - 'a';
            if(!nex[p][ch]) return 0;
            p = nex[p][ch];
        }
        if(ex[p]){
            return ++count[p];
        }
        return 0;
    }

}trie;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        char cc[51];
        scanf("%s",cc);
        trie.insert(cc);
    }
    int m;
    cin>>m;
    for(int i = 0; i<m; i++){
        char cc[51];
        scanf("%s",cc);
        int c = trie.search(cc);
        switch(c){
            case 0: cout << "WRONG" << endl; break;
            case 1: cout << "OK" << endl; break;
            default: cout << "REPEAT" << endl; break;
            break;
        }
    }
    return 0;
}