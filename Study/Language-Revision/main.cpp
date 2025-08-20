#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
    string input;
    cout << "Input A HEX Color" << endl;
    cin >> input;
    if (input.length() != 7) cout << "COLOR ERROR" << endl;
    else {
        input = input.substr(1, input.size() - 1);
        int colorCode;
        sscanf(input.c_str(), "%X", &colorCode);
        int r = (colorCode & 0xFF0000) >> 16;
        int g = (colorCode & 0xFF00) >> 8;
        int b = (colorCode & 0xFF);
        cout << r << " " << g << " " << b << endl;
        printf("#%2X%2X%2X\n", r, g, b);
    }
    return 0;
}