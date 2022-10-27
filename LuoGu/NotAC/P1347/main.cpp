#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int n,m;

struct Node{
    int val;
    int indeg = 0;

    char getVal(){
        return val + 'A';
    }

    const bool operator<(const Node &a) const{
        return this->indeg < a.indeg;
    }
}nds[30];

vector<int> G[30];
vector<int> ans;
int vis[30];

int Tsort(){
    priority_queue<Node> pq;
    int cnt = 0;
    for(int i = 0; i<n; i++){
        if(cnt>1){
            return -1;
        }
        if(vis[nds[i].val]==1 && nds[i].indeg == 0){
            pq.push(nds[i]);
            vis[i] = 1;
            cnt++;
        }
    }
    if(cnt == 0) return 1;
    while(!pq.empty()){
        Node x = pq.top();
        pq.pop();cnt = 0;
        for(int i = 0; i<G[x.val].size(); i++){
            if(cnt>1){
                return -1;
            }
            nds[G[x.val][i]].indeg--;
            if(nds[G[x.val][i]].indeg == 0){
                pq.push(nds[G[x.val][i]]);
                vis[i] = 1;
                cnt++;
            }
        }
        ans.push_back(x.val);
    }
    if(ans.size()==n){
        return 1;
    }
    return 0;
}

int main(){
    // Type your code here
    cin >> n >> m;
    for(int i = 0; i<26; i++){
        nds[i].val = i;
    }
    memset(vis,0,sizeof(vis));
    for(int i = 0; i<m; i++){
        string buf;
        cin >> buf;
        int a = buf[0] - 'A';
        int b = buf[2] - 'A';
        cout << a << " " << b << endl;
        int flag;
        nds[b].indeg++;
        G[a].push_back(b);
        vis[a] = vis[b] = 1;
        flag = Tsort();
        switch(flag){
            case 1:
                cout<<"Sorted sequence determined after "<<i+1<<" relations: " << endl;
                for(int j=0;j<n;j++)
                {
                    cout<<(char)(ans[j]+'A');
                }
                cout<<'.'<<endl;
                return 0;
            case 0:
                continue;
            default:
                cout<<"Inconsistency found after "<<i+1<<" relations."<<endl;
                return 0;
        }
    }
    cout<<"Sorted sequence cannot be determined."<<endl;
    return 0;
}