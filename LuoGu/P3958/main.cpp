#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

struct Point{
    long long x,y,z;
}PTS[100001];

int fa[100001];

long long dis(Point &A, Point &B){
    long long ans = (A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y)+(A.z-B.z)*(A.z-B.z);
    return ans;
}
long long n,h,r;

void init_set(){
    // n -> bottom, n+1 -> top
    for(int i = 0; i<n+2; i++) fa[i] = i;
}

int find(int x){
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void unite(int x, int y){
    if(find(x)!=find(y)) fa[find(x)] = find(y);
}

#define TOP n+1
#define BOTTOM n

int main() {
    int T;
    cin >> T;
    while(T--){
        cin >> n >> h >> r;
        init_set();
        for(int i = 0; i<n; i++){
            long long x,y,z;
            cin >> x >> y >> z;
            PTS[i].x = x;
            PTS[i].y = y;
            PTS[i].z = z;
            if(z+r >= h){
                unite(i, TOP);
            }
            if(z-r <= 0){
                unite(i, BOTTOM);
            }
            for(int j = 0; j<i; j++){
                double di = dis(PTS[i], PTS[j]);
                if(di <= 4 * r * r){
                    unite(i,j);
                }
            }
        }
        cout << ((find(TOP) == find(BOTTOM)) ? "Yes" : "No") << endl;
    }
    return 0;
}
