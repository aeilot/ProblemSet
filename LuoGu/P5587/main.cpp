#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Type your code here
    vector<string> key, ans;
    string buffer;
    while (getline(cin, buffer)) {
        if (buffer == "EOF") break;
        int pos = 0;
        while ((pos = buffer.find('<', pos)) != string::npos) {
            if (pos == 0) {
                buffer.erase(pos, 1);
            } else {
                buffer.erase(pos - 1, 2);
                pos--;
            }
        }
        // cout << buffer << endl;
        key.push_back(buffer);
    }
    /*
        erase 后 pos 应改变！！
    */
    while (getline(cin, buffer)) {
        if (buffer == "EOF") break;
        int pos = 0;
        while ((pos = buffer.find('<', pos)) != string::npos) {
            if (pos == 0) {
                buffer.erase(pos, 1);
            } else {
                buffer.erase(pos - 1, 2);
                pos--;
            }
        }
        // cout << buffer << endl;
        ans.push_back(buffer);
    }
    double time;
    cin >> time;
    int correct = 0;
    for (int i = 0; i < min(key.size(), ans.size()); i++) {
        for (int j = 0; j < min(key[i].size(), ans[i].size()); j++) {
            if (key[i][j] == ans[i][j] &&
                ((key[i][j] >= 'a' && key[i][j] <= 'z') || key[i][j] == ' ' ||
                 key[i][j] == '.'))
                correct++;
        }
    }
    printf("%.0f\n", round(correct / (double) time * 60.0));
    return 0;
}