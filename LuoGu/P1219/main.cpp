#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace	std;

int n;
int ans[14];
int cans = 0;

bool eval(int curn, int find){
	for(int i = 1; i<curn; i++){
		if(ans[i]==find) return false;
		if(abs(ans[i]-find)==abs(curn-i)) return false;
	}
	return true;
}


void dfs(int curn){
	if(curn>n){
		if(cans<3){
			for(int i = 1; i<=n; i++){
				cout << ans[i] << " ";
			}
			cout << endl;
		}
		cans++;
		return;
	}
	for(int i = 1; i<=n; i++){
		if(eval(curn, i)){
			/* if(curn >= 2) cout << i << "  " << curn << endl; */
			ans[curn] = i;
			dfs(curn+1);
		}
	}
}

int main(int argc, char* argv[]){
	cin >> n;
	memset(ans, 0, sizeof(ans));
	dfs(1);	
	cout << cans << endl;
	return 0;
}

