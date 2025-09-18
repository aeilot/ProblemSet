#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace	std;

constexpr int MAX_N = 500001;

int head[MAX_N*2];
int to[MAX_N*2];
int nxt[MAX_N*2];
int cnt = -1;

int LG[MAX_N];
int ST[MAX_N][23];

void add(int u, int v){
	nxt[++cnt] = head[u];
	head[u] = cnt;
	to[cnt] = v;
}

bool vis[MAX_N];
long long dep[MAX_N];

void init(int u){
	vis[u] = true;
	for(int i = 1; (1<<i) <=dep[u]; i++){
		ST[u][i] = ST[ST[u][i-1]][i-1];
	}
	for(int i = head[u]; i!=-1; i=nxt[i]){
		int y = to[i];
		if(vis[y]) continue;
		ST[y][0] = u;
		dep[y] = dep[u] + 1;
		init(y);
	}
}

int query(int a, int b){
	if(dep[a] > dep[b]) swap(a,b);
	while(dep[a]!=dep[b]){
		b = ST[b][LG[dep[b]-dep[a]]];
	}
	if(a==b){
		return a;
	}
	for(int i = LG[dep[a]]; i>=0; i--){
		if(ST[a][i] != ST[b][i]){
			a = ST[a][i];
			b = ST[b][i];
		}
	}
	return ST[a][0];
}

int main(int argc, char* argv[]){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);	
	int n,m,s;
	cin >> n >> m >> s;
	memset(head,-1,sizeof(head));
	for(int i = 2; i<MAX_N; i++){
		LG[i] = LG[i/2] + 1;
	}
	for(int i = 0; i<n-1; i++){
		int x,y;
		cin >> x >> y;
		add(x,y);
		add(y,x);
	}
	init(s);
	for(int i = 0; i<m; i++){
		int a,b;
		cin >> a >> b;
		cout << query(a,b) << endl;
	}
	return 0;
}

