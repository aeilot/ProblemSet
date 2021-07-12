#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace	std;

struct Farmer{
	int p,a;
};

Farmer flist[5000];

Farmer makeFarmer(int p, int a){
	Farmer ra;
	ra.p = p;
	ra.a = a;
	return ra;
}

bool cmp(const Farmer &a, const Farmer &b){
	if(a.p == b.p) return a.a < b.a;
	return a.p < b.p;
}

int main(int argc, char* argv[]){
	int n,m;
	cin >> n >> m;
	for(int i = 0; i<m; i++){
		int p,a;
		cin >> p >> a;
		flist[i] = makeFarmer(p,a);
	}
	sort(flist, flist+m, cmp);
	int sum = 0;
	int p = 0;
	for(int i = 0; i<m; i++){
		if(sum >= n) break;
		if(flist[i].a > n - sum){
			p += flist[i].p * (n - sum);
			sum += n - sum;
		} else {
			sum += flist[i].a;
			p += flist[i].p * flist[i].a;
		}
	}
	cout << p << endl;
	return 0;
}

