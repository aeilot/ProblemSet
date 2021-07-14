#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    vector<vector<int> > sets;
    int n;
    cin >> n;
    sets.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            int tmp;
            cin >> tmp;
            sets.at(i).push_back(tmp);
        }
    }
	int cnt[800];
	int ans[800];
	for(int i = 0; i <= n; i++){
		cnt[i] = -1;
		ans[i] = -1;
	}
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < sets.at(i).size(); j++) {
			if(cnt[sets.at(i).at(j)]==-1){
				cnt[sets.at(i).at(j)] = n-i;
			}
        }
    }
	for(int i = 1; i<=n; i++){
		if(ans[cnt[i]]!=-1){
			ans[n-cnt[i]] = i;
		}else{
			ans[cnt[i]] = i;
		}
	}
	for(int i = 1; i<=n; i++){
		cout << ans[i] << " ";
	}
	cout << endl;
    return 0;
}
