#include <iostream>
#include <cstdio>

using namespace	std;

int block[2][2];
int last[2][2];
int listB[4];
int listL[4];

bool isValid(int k){
	if(k==1) return true;
	if(k==2){
		return true;
	}
	if(listB[0] == listL[0] && listB[1] == listL[1] && listB[2] == listL[2])
		return true;
	else if(listB[0] == listL[2] && listB[1] == listL[0] && listB[2] == listL[1])
		return true;
	else if(listB[0] == listL[1] && listB[1] == listL[2] && listB[2] == listL[0])
		return true;
	else return false;
}

int main(int argc, char* argv[]){
	int cnt = 0;
	int tmp = 0;
	int tmp2 = 0;
	for(int i = 0; i<2; i++){
		for(int j = 0; j<2; j++){
			cin >> block[i][j];
			if(block[i][j] != 0){
				cnt ++;
			}
		}
	}
	int cnt2 = 0;
	swap(block[1][0], block[1][1]);
	for(int i = 0; i<2; i++){
		for(int j = 0; j<2; j++){
			cin >> last[i][j];
			if(last[i][j] != 0){
				cnt2 ++;
			}
		}
	}
	swap(last[1][0], last[1][1]);
	if(cnt==4 || cnt2 == 4 ){
		int check = 0;
		for(int i = 0; i<2; i++){
			for(int j = 0; j<2; j++){
				if(block[i][j]==last[i][j]) check++;	
			}
		}
		if(check == 4) cout << "Yes" << endl;
		else	cout << "No" << endl;
		return 0;
	}else if(cnt == 0 || cnt2 == 0){
		cout << "Yes" << endl;
		return 0;
	}
	for(int i = 0; i<2; i++){
		for(int j = 0; j<2; j++){
			if(block[i][j] != 0) listB[tmp++] = block[i][j];
			if(last[i][j] != 0) listL[tmp2++] = last[i][j];
		}
	}
	if(tmp != tmp2){
		cout << "No" << endl;
		return 0;
	}
	bool ans = isValid(cnt);
	if(ans) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}

