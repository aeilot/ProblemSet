#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string tmp;
    int count = 0;
    while (cin >> tmp) {
        for(int i = 0; i<tmp.size(); i++){
            if((tmp[i]>='A'&&tmp[i]<='Z')||(tmp[i]>='a'&&tmp[i]<='z')||(tmp[i]>='0'&&tmp[i]<='9')){
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}