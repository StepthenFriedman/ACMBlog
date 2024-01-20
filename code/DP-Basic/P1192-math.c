#include <stdio.h>
#define mod 100003LL

/*
a routine of 100003 destroy the ascending character of the sequence.
therefore unsigned long long would cause WA.
*/

long long n,k,a[1000000],ans=0;
int main(){
    while (~scanf("%lld%lld",&n,&k)){
        a[0]=a[1]=1;
        for (int i=2;i<=k;i++)
            a[i]=(a[i-1]*2)%mod;
        for (int i=k+1;i<=n;i++)
            a[i]=(a[i-1]*2-a[i-k-1])%mod;
        ans=(a[n]+mod)%mod;
        /*
        use (a[n]+mod)%mod to convert nagative into positive.
        */
        printf("%lld\n",ans);
    }
    return 0;
}