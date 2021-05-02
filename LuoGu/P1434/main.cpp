#include <iostream>
#include <cstdio>

int MAP[100][100];
int dp[100][100];
int r,c;

using namespace	std;

int dpf(int i, int j){
	int res = 0;
	if(MAP[i][j]==1) return 1;
	if(i-1>=0){
		if(MAP[i-1][j]<MAP[i][j]) res = dp[i-1][j] +1;
	}
	if(i+1<=r){
		if(MAP[i+1][j]<MAP[i][j]) res = max(res, dp[i+1][j] +1);
	}
	if(j-1>=0){
		if(MAP[i][j-1]<MAP[i][j]) res = max(res, dp[i][j-1] +1);
	}
	if(j+1<=c){
		if(MAP[i][j+1]<MAP[i][j]) res = max(res, dp[i][j+1] +1);
	}
	return res;
}

int main(int argc, char* argv[]){
	cin >> r >> c;
	for(int i = 0; i<r; i++){
		for(int j=0; j<c; j++){
			int m;
			cin >> m;
			MAP[i][j] = m;
		}
	}

	for(int i = 0; i<r; i++){
		for(int j=0; j<c; j++){
			dp[i][j] = dpf(i,j);
		}
	}
	
	return 0;
}

