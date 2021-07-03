#include <iostream>
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
	}
	for(int i = 0; i < 2*n; i++){
		
	}
	return 0;
}

