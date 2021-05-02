#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>

using namespace	std;

pair<int, int> max_ran(vector<int> &a, int l, int r){
	int n = -1, h=0;
	for(int i = l; i<r; i++){
		if(a[i]>n){
			n = a[i];
			h = i;
		}
	}
	return make_pair(n, h);
}

int main(int argc, char* argv[]){
	int n;
	cin >> n;
	n = (1 << n);
	vector<int> arr;
	for(int i = 0; i<n; i++){
		int tmp; 
		cin >> tmp; 
		arr.push_back(tmp);
	}
	if(n==2){
		if(arr[0]>arr[1]){
			cout << 2 << endl;
			return 0;
		}else{
			cout << 1 << endl;
			return 0;
		}
	}
	pair<int, int> l=max_ran(arr, 0, n/2), r=max_ran(arr,n/2-1,n);
	int la = l.first, ra = r.first;
	int res = la>ra ? r.second : l.second;
	res++;
	cout << res << endl;
	return 0;
}

