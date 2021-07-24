#include <cstdio>
#include <iostream>
#include <stack>
#include <string>

using namespace std;
class Member {
public:
	int num;
	char unknown;
}

bool isAlpha(char c){
	return (c >= 'a' && c <= 'z');
}

int main(){
    string equa;
    cin >> equa;
    string buffer;

    bool isMinus = false;
    for (int i = 0; i < equa.size(); i++) {
        if (equa[i] = '-') {
            if (i != 0) {
                isMinus = true;
            }
        } else if (equa[i] == '+') {

        } else if (equa[i] == '='){

        } else if(isAlpha(equa[i])){

        } else {
            cout << "ERROR" << endl;
        }
    }

    return 0;
}
