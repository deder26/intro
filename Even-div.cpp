#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<bits/stdc++.h>
#define max 10000000
using namespace std;
bool prime[max];
int primes[max];
//int fact[700000][2];
int siv()
{
    int i,j,k;
    int n;
    n=sqrt(max);
    prime[1]=true;
    prime[2]=false;
    for(i=4;i<=max;i+=2)prime[i]=true;
    for(j=3;j<n;j+=2){
            if(prime[j]==0){
                    for(k=j*j;k<=max;k+=j){
                        prime[k]=true;
                    }
            }
    }
    int p=0;
    for(int q=1;q<max;q++){
        if(prime[q]==false){
            primes[p]=q;
            p++;
        }
    }
    //cout<<p<<endl;
}
int primefact(int n,int fact[][2]){
    int i=0,j=0;
    while(n!=1){
        if(n%primes[i]==0){
            fact[j][0]=primes[i];
            fact[j][1]=0;
            while(n%primes[i]==0){
                n=n/primes[i];
                fact[j][1]++;
            }
            j++;
        }
        i++;

    }
    return j;
}
long long shokti(long long a,long long b){
    if(b==0)
        return 1;
    long long x=shokti(a,b/2);
    x=(x*x);
    if(b%2==1)
        x=(x*a);
    return x;
}
int main()
{
    siv();
    int tc,t=0;
    scanf("%d",&tc);
    while(t<tc){
        t++;
        int fact[100000][2];
        int n;
        scanf("%d",&n);
        int len=primefact(n,fact);
        long long res=1;
        long long sum;
        if(fact[0][0]==2){
            for(int i=0;i<len;i++){
                sum=0;
                for(int j=0;j<=fact[i][1];j++){
                    if(fact[i][0]==2 && j==0)continue;
                        sum=sum+shokti(fact[i][0],j);

                    }
                res=res*sum;
            }
        }
        else
            res=0;
        printf("%lld\n",res);
    }
    return 0;
}
