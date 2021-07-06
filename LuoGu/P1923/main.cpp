#include <iostream>
#include <cstdio>

using namespace	std;

int n,k;
int AR[5000001];
int query(int sta, int end){
	int mid = AR[(sta+end)/2];
	int i = sta; 
	int j = end;
	do{
		while(AR[i]<mid) i++;
		while(AR[j]>mid) j--;
		if(i<=j){
			swap(AR[i],AR[j]);
			i++; j--;
		}
	}while(i<=j);
	if(k<=j) query(sta,j);
	else if(i<=k) query(i,end);
	else{
		return AR[j+1];
	}
}

int main(int argc, char* argv[]){
	cin >> n >> k;
	for(int i = 0; i<n; i++){
		AR[i] = 0;
		scanf("%d",&AR[i]);
	}
	int ans = query(0, n-1);
	cout << ans << endl;
	return 0;
}

