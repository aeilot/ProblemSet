#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace	std;

struct one{
	int n;
	int sc;
	int cap;
};

one makeOneEmpty(){
	one a;
	return a;
}

one makeOne(int n, int sc, int cap){
	one a;
	a.n = n;
	a.cap = cap;
	a.sc = sc;
	return a;
}

one mem[200000];

bool cmp(const one &a, const one &b){
	if(a.sc != b.sc) return a.sc > b.sc;
	return a.n < b.n;
}

int main(int argc, char* argv[]){
	int n,r,q;
	cin >> n >> r >> q;
	for(int i = 0; i< 2*n; i++){
		mem[i] = makeOneEmpty();
		mem[i].n = i;
	}
	for(int i = 0; i < 2*n; i++){
		int tmp;
		cin >> tmp;
		mem[i].sc = tmp;
	}
	for(int i = 0; i < 2*n; i++){
		int tmp;
		cin >> tmp;
		mem[i].cap = tmp;
	}
	for(int i = 0; i<r; i++){
		sort(mem,mem+2*n,cmp);
		for(int j = 0; j<2*n; j+=2){
			if(j+1<2*n){
				one fmr = mem[j];
				one ltr = mem[j+1];
				if(fmr.cap >= ltr.cap){
					fmr.sc++;	
				}else{
					ltr.sc++;
				}
			}
		}
	}
	cout << mem[0].n+1 << endl;
	return 0;
}

