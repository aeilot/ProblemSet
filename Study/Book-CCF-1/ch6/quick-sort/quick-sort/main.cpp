//
//  main.cpp
//  quick-sort
//
//  Created by Louis Aeilot on 2020/10/16.
//

#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>

using namespace std;

const int MAXN = 100005;
int A[MAXN], N;

// lower_bound: 第一个大于等于
// upper_bound: 第一个大于

void quick_sort(int L, int R){
    if(R<=L) return;
    int T = A[rand()%(R-L+1)+L], i=L, j=R;
    while(i<=j){
        while(A[i]>T) i++;
        while(A[j]<T) j--;
        
        if(i<=j){
            swap(A[i], A[j]);
            i++;
            j--;
        }
    }
    quick_sort(L, j);
    quick_sort(i, R);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    cin >> N;
    for (int i = 0; i<N; i++) {
        cin >> A[i];
    }
    srand(int(time(0)));
    quick_sort(0, N);
    for (int i =0; i<N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
