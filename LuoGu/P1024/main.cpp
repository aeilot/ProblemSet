#include <iostream>
#include <cstdio>
#include <cmath>

using namespace	std;

double a,b,c,d;
double f(double x){
	return a*x*x*x + b*x*x + c*x +d;
}

double find(double fst, double lst){
	if(lst-fst<0.01){
		return (lst+fst)/2;
	}
	double mid = (fst+lst)/2;
	double sta = f(fst);
	double cet = f(mid);
	double end = f(lst);
	if(sta*cet <=0) return find(fst, mid);
	else return find(mid, lst);
}

int main(int argc, char* argv[]){
	cin >> a >> b >> c >> d;
	for(int i = -100; i<=99; i+=1){
		if(f(i)==0){
			printf("%.2f ",double(i));
		}else if(f(i)*f(i+1)<0){
	    	double rt = find(i,i+1);
			printf("%.2f ", rt);
		}
	}
	printf("\n");
	return 0;
}

