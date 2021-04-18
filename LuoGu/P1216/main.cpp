#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace	std;

int PYRAMID[1000][1000] = {-1};
int DP[1000] = {-1};


int main(int argc, char* argv[]){
	int n;
	cin >> n;
	for(int i = 0; i <n; i++){
		for(int j = 0; j<=i; j++){
			cin >> PYRAMID[i][j];
		}
	}
	DP[0] = PYRAMID[0][0];
	if(n==1){
		cout << DP[0] << endl;
		return 0;
	}
	for(int i =1; i<n; i++){
		for(int j=i; j>=0; j--){
			if(j==0){
				DP[j] = PYRAMID[i][j] + DP[j];
			}else DP[j] = PYRAMID[i][j] + max(DP[j], DP[j-1]);
		}
	}
	int tmp = -1;
	for(int i = 0; i<n; i++){
		if(DP[i]>tmp) tmp = DP[i];
	}
	cout << tmp << endl;
	return 0;
}

