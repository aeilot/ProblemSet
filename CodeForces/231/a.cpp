#include <iostream>
#include <cstdio>

using namespace std;

int main(){
   int n;
   int f = 0;
   int tmpA,tmpB,tmpC;
   scanf("%d",&n);
   for(int i=0; i<n; i++){
       scanf("%d %d %d",&tmpA,&tmpB,&tmpC);
       if(tmpA+tmpB+tmpC>=2) f++;
   }
   printf("%d\n",f);
   return 0;
}
