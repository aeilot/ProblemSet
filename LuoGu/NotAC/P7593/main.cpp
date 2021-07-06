#include <iostream>
#include <cstdio>
#include <cmath>

using namespace	std;

bool isFraction(double i){
	return i-floor(i)!=0;
}

int main(int argc, char* argv[]){
	int t;
	cin >> t;
	for(int i = 0; i<t; i++){
		int n,k,s;
		int sign = 0;
		cin >> n >> k >> s;
		double mid = double(s)/double(k);
		if(mid<=n-k/2){
			if(k%2!=0){
				if(isFraction(mid)) cout << "No" << endl;
				else cout << "Yes" << endl;
			}else{
				if(isFraction(mid)) cout << "Yes" << endl;
				else cout << "No" << endl;
			}
		}
		else{
			cout << "No" << endl;
		}
	}
	return 0;
}

