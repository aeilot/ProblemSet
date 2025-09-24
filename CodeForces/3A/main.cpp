#include <iostream>
#include <cstdio>
#include <cmath>

using namespace	std;

int main(int argc, char* argv[]){
	char x1,x2;
	int y1,y2;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	bool fgv = (y2-y1) < 0;
	bool fgh = (x2-x1) < 0;
	int vd = abs(y2-y1);
	int hd = abs(x2-x1);
	char vo = fgv ? 'D' : 'U';
	char ho = fgh ? 'L' : 'R';
	int ans = max(vd,hd);
	cout << ans << endl;
	while(vd<hd){
		cout << ho << endl;
		hd--;
	}
	while(vd>hd){
		cout << vo << endl;
		vd--;
	}
	while(vd>0){
		cout << ho << vo << endl;
		vd--;
	}
	return 0;
}

