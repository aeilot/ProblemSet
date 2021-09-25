#include <iostream>
#include <cstdio>

using namespace	std;

#define MAXN 13010

int w[MAXN], d[MAXN];
int dp[MAXN];

int main(int argc, char* argv[]){
	int n,m;
	cin >> n >> m;
	for(int i = 0; i<n; i++){
		cin >> w[i] >> d[i];
	}
	for(int i = 0; i<n; i++)
		for(int j = m; j>=w[i]; j--)
			dp[j] = max(dp[j],dp[j-w[i]]+d[i]);
	cout << dp[m] << endl;
	return 0;
}

