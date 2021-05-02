#include <iostream>
#include <cstdio>
#include <string>
#include <stdlib.h>

using namespace	std;

bool cmp(string &a, string &b){
	if(a.size()!=b.size()) return a.size() > b.size();
	for(int i = 0; i<a.size(); i++){
		int numa = (a.c_str())[i] - '0';
		int numb = (b.c_str())[i] - '0';
		if(numa!=numb){
			return numa > numb;
		}
	}
	return false;
}

int main(int argc, char* argv[]){
	int maxi=0, n;
	string max;
	cin >> n;
	for(int i =0; i<n; i++){
		string tmp;
		cin >> tmp;
		if(cmp(tmp,max)){
			max = tmp;
			maxi = i;
		}
	}
	cout << maxi+1 << endl << max << endl; 
	return 0;
}

