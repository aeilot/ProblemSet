#include <cstdio>
#include <cmath>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Side{
	int unknown;
	int number;
	
	Side(int unknown, int number){
		this->unknown = unknown;
		this->number = number;
	}
	
	Side(){
		unknown = 0;
		number = 0;
	}
};

bool isNumber(char a){
	return a>='0' && a<='9';
}

bool isAlpha(char a){
	return a>='a' && a<='z';
}

Side parse(string &opr){
	Side ra;
	int i = 0;
	int buffer = 0;
	while(i<opr.length()){
		if(buffer == 0){
			if(opr[i]=='-'){
				buffer = -1;
				i++;
			}else{
				buffer = 1;
			}
			if(opr[i]=='+') i++;
		}
		int tmpc = 0;
		stack<int> mem;
		while(isNumber(opr[i])){
			mem.push(opr[i]-'0');
			//printf("In: %d\n", opr[i]-'0');
			tmpc++;
			i++;
		}
		//printf("TMPC: %d, I: %d\n",tmpc,i);
		int tmp = 0;
		for(int j = 0; j<tmpc;j++){
			int t = mem.top();
			mem.pop();
			tmp+=t*pow(10,j);
		}
		tmp*=buffer;
		//printf("Get Number: %d\n", tmp);
		if(isAlpha(opr[i])){
			if(tmp!=0) ra.unknown += tmp;
			else ra.unknown+=1*buffer;
			i++;
		}else{
			ra.number += tmp;
		}
		buffer = 0;
	}
	return ra;
}

int main(){
	string input;
	cin >> input;
	string left;
	string right;
	int t;
	char name = '0';
	for(int i = 0; i<input.length(); i++){
		if(name == '0' && input[i]>='a' && input[i]<='z'){
			name = input[i];
		}
		if(input[i]=='='){
			left = input.substr(0,i);
			t = i+1;
		}
		if(i==input.length()-1){
			right = input.substr(t,i);
		}
	}
	//cout << left << endl << right << endl;
	Side lft = parse(left);
	Side rgt = parse(right);
	int un = lft.unknown - rgt.unknown;
	int num = rgt.number - lft.number;
	double ans = double(num)/double(un);
	cout << name << "=";
	if(ans!=0) printf("%.3lf\n", ans);
	else printf("0.000\n");
	return 0;
}
