#include <iostream>
#include <algorithm>

using namespace std;

class Com{
public:
    int k, s;
    Com();
    Com(int k, int s){
        this->k = k;
        this->s = s;
    }
};

bool cmp(const Com &a, const Com &b){
    if(a.s!=b.s) return a.s<b.s;
    return a.k<b.k;
}

Com AR[10000];

int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        int k,s;
        cin >> k >> s;
        AR[i] = Com(k,s);
    }
    sort(AR, AR+n, cmp);
    for(int i = 0; i<n; i++){
        cout << AR[i].k <<AR[i].s << endl;
    }
    return 0;
}