#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace	std;

struct mem{
	int no;
	int time;
};

mem make_mem(int no, int time){
	mem rv;
	rv.no = no;
	rv.time = time;
	return rv;
}

mem T[1000];

bool cmp(const mem &a, const mem &b){
	if(a.time==b.time) return a.no<b.no;
	return a.time < b.time;
}

int main(int argc, char* argv[]){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int tim;
		cin >> tim;
		T[i] = make_mem(i+1, tim);
	}
	sort(T, T+n, cmp);	
	double sum = 0;
	for(int i = 0; i<n; i++){
		cout << T[i].no << " ";
		sum+= T[i].time*(n-i-1);
	}
	double average = sum/n;
	cout << endl;
	printf("%.2f\n",average);
	return 0;
}

