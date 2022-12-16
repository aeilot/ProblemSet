#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <climits>

using namespace std;

long long V[100010];

struct Node{
    int next, to;
}NDS[100010];

int head[100010], cnt = 0;
int in[100010];

void add(int x, int y){
    NDS[cnt].to = y;
    NDS[cnt].next = head[x];
    head[x] = cnt++;
}

bool vis[100010];
long long ans =0;
long long mmin = INT_MAX;
void dfs(int x){
    vis[x] = 1;
    mmin = min(mmin,V[x]);
    ans += V[x];
    for(int i = head[x]; i!=-1; i=NDS[i].next){
        int y = NDS[i].to;
        if(vis[y]) return;
        dfs(y);
    }
}

struct ppos{
    int id, in;
    const bool operator<(const ppos & x) const{
        return x.in < this->in;
    }
};
int N;

void topo(){
    priority_queue<ppos> q;
    for(int i = 1; i<=N;i++){
        if(in[i]==0) q.push({i,in[i]});
    }
    while(!q.empty()){
        int t = q.top().id;
        q.pop();
        ans += V[t];
        vis[t] = 1;
        for(int i = head[t]; i!=-1; i=NDS[i].next){
            int y =NDS[i].to;
            in[y]--;
            if(in[y]==0){
                q.push({y,in[y]});
            }
        }
    }
}

int main(){
    // Type your code here
    memset(head,-1,sizeof(head));
    cin >> N;
    for(int i = 1; i<=N;i++){
        int t;
        cin >> t >> V[i];
        add(i,t);
        in[t]++;
    }
    topo();
    for(int i = 1; i<=N;i++){
        if(!vis[i]){
            mmin = INT_MAX;
            dfs(i);
            ans -= mmin;
        }
    }
    cout << ans << endl;
    return 0;
}