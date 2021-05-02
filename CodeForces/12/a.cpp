#include <iostream>
#include <cstdio>

using namespace	std;

int main(int argc, char* argv[]){
	char matrix[3][3];
	for(int i = 0; i<3; i++){
		for(int j = 0; j<3; j++){
			cin >> matrix[i][j];
		}
	}
	if(matrix[0][0]==matrix[2][2] && matrix[0][1]==matrix[2][1] && matrix[0][2] == matrix[2][0] && matrix[1][0] == matrix[1][2]) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}

