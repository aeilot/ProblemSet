#include <iostream>
#include <cstdio>
#include <stack>
#include <string>

using namespace std;

struct member{
	int number;
	bool isUnknown;	
};

struct expr{
	member unknown;
	member number;
};

int main(){
	string equa;
	cin >> equa;
	
	int minus_mark = 1;
	char name;
	for(int i = 0; i<equa.size(); i++){
		char a = equa[i];
		if(a=='-'){

		}else if(a=='+'){

		}else if(a=='='){

		}else{

		}
	}
	return 0;
}
