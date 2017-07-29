#include<bits/stdc++.h>
using namespace std;

int sum_div(int n)
{
    int sum,i,j,k,l,m;
    l=1;
    k=1;
    sum=0;
    while(n%2==0)
    {
        l=l*2;
        sum=sum+l;
        n=n/2;
    }
    k=k*sum;
    for(i=3;i<=sqrt(1.0*n);i=i+2)
    {
        sum=1;
        l=1;
        while(n%i==0)
        {
            l=l*i;
            sum=sum+l;
            n=n/i;
        }
        k=k*sum;
    }
    sum=1;
    if(n>2)
    {
        sum=sum+n;
        k=k*sum;
    }
    return k;
}


int main()
{
    int n,t,sum;
    scanf("%d",&t);
    while(t--)
    {
        cin>>n;
        if(n==0 || n%2==1) sum=0;
        else sum=sum_div(n);
        printf("%d\n",sum);
    }
    return 0;

}
