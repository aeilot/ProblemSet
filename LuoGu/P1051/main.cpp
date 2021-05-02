#include<iostream>
using namespace std;
int main()
{
    int n,score1,score2,sum=0,max=0,total=0,x,i;
    char a,b;
    string name,maxn;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>name>>score1>>score2>>a>>b>>x;
        if(score1>80 && x>0)
            sum+=8000;
        if(score1>85 && score2>80)
            sum+=4000;
        if(score1>90)
            sum+=2000;
        if(score1>85 && b=='Y')
            sum+=1000;
        if(score2>80 && a=='Y')
            sum+=850;
        total+=sum;
        if(sum>max)
            maxn=name,max=sum;
        sum=0;
    }
    cout<<maxn<<endl<<max<<endl<<total;
    return 0;
}
