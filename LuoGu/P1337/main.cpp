#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>

using namespace	std;

const int MAX_N = 1010;
int X[MAX_N], Y[MAX_N], W[MAX_N];

double Rand() { return (double)rand() / RAND_MAX; }

double ansx, ansy, dis;
int n;

double calc(double xx, double yy){
	double res = 0;
	for(int i = 0; i<n; i++){
		double tx = X[i] - xx;
		double ty = Y[i] - yy;
		res += sqrt(tx*tx + ty*ty) * W[i];
	}
	if(res<dis){
		dis = res;
		ansx = xx;
		ansy = yy;
	}
	return res;
}

void SA(){
	double t = 100000;
	double nowx = ansx, nowy = ansy;
	while(t>0.001){
		double nxtx = nowx + t*(Rand()*2 - 1);
		double nxty = nowy + t*(Rand()*2 - 1);
		double delta = calc(nxtx, nxty) - calc(nowx, nowy);
		if(exp(-delta/t)>Rand()) nowx = nxtx, nowy = nxty;
		t *= 0.97;
	}
	for(int i = 0; i<=1000; i++){
		double nxtx = ansx + t*(Rand()*2 - 1);
		double nxty = ansy + t*(Rand()*2 - 1);
		calc(nxtx, nxty);
	}
}

int main(int argc, char* argv[]){
	cin >> n;
	for(int i = 0; i<n; i++){
		cin >> X[i] >> Y[i] >> W[i];
		ansx += X[i];
		ansy += Y[i];
	}
	srand(time(NULL));
	ansx /= n;
	ansy /= n;
	dis = calc(ansx, ansy);
	SA();
	printf("%.3lf %.3lf\n", ansx, ansy);
	return 0;
}

