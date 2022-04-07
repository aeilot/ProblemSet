#include <iostream>
#include <cstdio>
#include <cmath>

using namespace	std;

struct box{
	int pencil;
	int cost;
}store[3];

int main(int argc, char* argv[]){
	double n;
	cin >> n;
	int tp = -100;
	for(auto i : store){
		cin >> i.pencil >> i.cost;	
		int tmp;
		tmp = ceil(n/i.pencil);
		tmp *= i.cost;
		if(tp<0) tp = tmp;
		else tp = min(tp, tmp);
	}
	cout << tp << endl;
	return 0;
}

