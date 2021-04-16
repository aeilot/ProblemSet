#include <cstring>
#include <iomanip>
#include <iostream>
#include <cstdio>

using namespace	std;

int n =0 ;

int MEM2[9] = {0};

void xxx(int t, int c, bool MEM[10]){
	MEM2[c++]=t;
	MEM[t] = true;
	if(c==n){
		for(int i = 0; i<n; i++){
			cout << std::setw(5) << MEM2[i];
		}
		cout << endl;
		return;
	}
	for(int i = 1; i<=n; i++){
		if(!MEM[i]){ 
			bool tmp[10];
			memcpy(tmp, MEM, 10 * sizeof(bool));
			xxx(i, c, tmp);
		}
	}
}

int main(int argc, char* argv[]){
	cin >> n;
	for(int i = 1; i<=n; i++){
		bool q[10] = {false};
		xxx(i, 0, q);
	}
	return 0;
}

