/*
 * @Author: Louis Aeilot 
 * @Date: 2020-07-29 21:57:51 
 * @Last Modified by:   Louis Aeilot 
 * @Last Modified time: 2020-07-29 21:57:51 
 */
#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

#define int long long
int n, k, a, b, c, t, type1[200005], type2[200005], type3[200005], cnt1, cnt2, cnt3, ans;
signed main()
{
    cin >> k >> n;
    for (int i = 1; i <= k; i++)
    {
        cin >> a >> b >> c;
        if (b == 0 && c == 0)
            continue;
        if (b == 0 && c == 1)
            type3[++cnt3] = a;
        if (b == 1 && c == 0)
            type2[++cnt2] = a;
        if (b == 1 && c == 1)
            type1[++cnt1] = a;
    }
    sort(type3 + 1, type3 + cnt3 + 1);
    sort(type2 + 1, type2 + cnt2 + 1);
    for (int i = 1; i <= min(cnt3, cnt2); i++)
        type1[++cnt1] = type3[i] + type2[i];
    sort(type1 + 1, type1 + cnt1 + 1);
    if (cnt1 < n)
    {
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= n; i++)
        ans += type1[i];
    cout << ans;
}