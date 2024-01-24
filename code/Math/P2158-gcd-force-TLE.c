#include <stdio.h>

long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}

int main(){
    long long n,i,j;
    long long ans=0;
    scanf("%lld",&n);
    if (n==1){
        printf("0\n");
        return 0;
    }
    if (n==2){
        printf("2\n");
        return 0;
    }
    for (i=2;i<n;i++){
        for (j=1;j<i;j++){
            if (gcd(i,j)==1){
                ans++;
            }
        }
    }
    ans=ans*2+3;
    printf("%lld\n",ans);
}