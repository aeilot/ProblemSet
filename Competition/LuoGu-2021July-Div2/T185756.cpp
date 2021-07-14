#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define P 998244353

using namespace	std;

class diamond{
	public:
	char oper;
	long long num;
	
	long long getVal(long long n){
		if(oper=='+'){
			return n+num;
		}
		if(oper=='*'){
			return n*num;
		}
		return -1;
	}
};

diamond makeDiamond(char oper, long long num){
	diamond rv;
	rv.oper = oper;
	rv.num = num;
	return rv;
}

diamond DList[100000];
diamond DDList[100000];

long long power = 0;
int n;

int cntMM = 0;
int cntMP = 0;
int cntPP = 0;
int cntPM = 0;

void cmp(){
	int n1 = 0;
	for(int i = 0; i<n; i++){
		diamond tmp = DList[i];
		if(tmp.num >0 && tmp.oper == '+'){
			DDList[n1++] = tmp;
		}
	}
	for(int i = 0; i<n; i++){
		diamond tmp = DList[i];
		if(tmp.oper == '*'){
			DDList[n1++] = tmp;
		}
	}	
	for(int i = 0; i<n; i++){
		diamond tmp = DList[i];
		if(tmp.oper == '+' && tmp.num <= 0){
			DDList[n1++] = tmp;
		}
	}	
}

void cmp_2(){
    int n1 = 0;
    int min = P;
    int minI = -1;
    int min2 = P;
    int min2I = -1;
    for(int i = 0; i<n; i++){
        diamond tmp = DList[i];
        if(tmp.oper == '*' && tmp.num < 0){
            if(abs(tmp.num) < min){
                min2 = min;
                min2I = minI;
                min = abs(tmp.num);
                minI = i;
            }
        }
    }
    DDList[n1++] = DList[minI];
    for(int i = 0; i<n; i++){
        if(i==minI || i==min2I) continue;
        diamond tmp = DList[i];
        if(tmp.oper == '+' && tmp.num <= 0){
            DDList[n1++] = tmp;
        }
    }
    DDList[n1++] = DList[min2I];
    for(int i = 0; i<n; i++){
        if(i==minI || i==min2I) continue;
        diamond tmp = DList[i];
        if(tmp.num >0 && tmp.oper == '+'){
            DDList[n1++] = tmp;
        }
    }
    for(int i = 0; i<n; i++){
        if(i==minI || i==min2I) continue;
        diamond tmp = DList[i];
        if(tmp.oper == '*'){
            DDList[n1++] = tmp;
        }
    }
}

void cmp3(){
	int n1 = 0;
	int min = P;
	int minI = -1;
    if(cntMM >=1){
        for(int i = 0; i<n; i++){
            diamond tmp = DList[i];
            if(tmp.oper == '*' && tmp.num < 0){
                if(abs(tmp.num) < min){
                    min = abs(tmp.num);
                    minI = i;
                }
            }
        }
        DDList[n1++] = DList[minI];
    }
	for(int i = 0; i<n; i++){
		if(i==minI) continue;
		diamond tmp = DList[i];
		if(tmp.oper == '+'){
			DDList[n1++] = tmp;
		}
	}	
	for(int i = 0; i<n; i++){
		if(i==minI) continue;
		diamond tmp = DList[i];
		if(tmp.oper == '*'){
			DDList[n1++] = tmp;
		}
	}	
}

void cmp2(){
	int n1 = 0;
	for(int i = 0; i<n; i++){
		diamond tmp = DList[i];
		if(tmp.num <0 && tmp.oper == '+'){
			DDList[n1++] = tmp;
		}
	}
	for(int i = 0; i<n; i++){
		diamond tmp = DList[i];
		if(tmp.oper == '*' && tmp.num < 0){
			DDList[n1++] = tmp;
		}
	}	
	for(int i = 0; i<n; i++){
		diamond tmp = DList[i];
		if(tmp.oper == '+' && tmp.num >= 0){
			DDList[n1++] = tmp;
		}
	}	
	for(int i = 0; i<n; i++){
		diamond tmp = DList[i];
		if(tmp.oper == '*' && tmp.num > 0){
			DDList[n1++] = tmp;
		}
	}	
}

void cmp4(){
	int n1 = 0;
	int min = P;
	int minI = -1;
    if(cntMM >=1){
        for(int i = 0; i<n; i++){
            diamond tmp = DList[i];
            if(tmp.oper == '*' && tmp.num < 0){
                if(abs(tmp.num) < min){
                    min = abs(tmp.num);
                    minI = i;
                }
            }
        }
    }
	DDList[n1++] = DList[minI];
	for(int i = 0; i<n; i++){
		if(i==minI) continue;
		diamond tmp = DList[i];
		if(tmp.oper == '+'){
			DDList[n1++] = tmp;
		}
	}	
	for(int i = 0; i<n; i++){
		if(i==minI) continue;
		diamond tmp = DList[i];
		if(tmp.oper == '*'){
			DDList[n1++] = tmp;
		}
	}	
}

int main(int argc, char* argv[]){
	cin >> n;
	for(int i = 0; i<n; i++){
		char oper;
		cin >> oper;
		long long num;
		cin >> num;
		DList[i] = makeDiamond(oper,num);
        if(num<0 && oper == '*') cntMM++;
		if(num<0 && oper == '+') cntMP++;
		if(num>0 && oper == '+') cntPP++;
		if(num>0 && oper == '*') cntPM++;
	}
	if(cntMM + cntMP == 0 || cntMP + cntPP == 0){
		for(int i = 0; i<n; i++){
			DDList[i] = DList[i];
		}
	}
	else if(cntMM%2 == 0){
        if(cntPP > 0){
            cmp();
            for(int i = 0; i<n; i++){
                power = DDList[i].getVal(power);
            }
            if(cntMP > 0 && cntMM >= 3){
                int sav = power;
                power = 0;
                cmp_2();
                for(int i = 0; i<n; i++){
                    power = DDList[i].getVal(power);
                }
                if(power>sav) sav = power;
            }
            cout << (power % P + P) % P << endl;
            return 0;
        }
		else if(cntMM >= 2) cmp3();
        else cmp();
	}else{
		if(cntMP>0) cmp2();
		else if(cntMM > 2) cmp4();
        else cmp2();
	}
	for(int i = 0; i<n; i++){
		power = DDList[i].getVal(power);
	}
	cout << (power % P + P) % P << endl; 
	return 0;
}
