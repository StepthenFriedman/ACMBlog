#include<stdio.h>

int MOD;

long long power(long long x,int n){
    if (n<2) return x%MOD;
    else if (n%2) return ((power(x,n-1)%MOD)*x)%MOD;
    else return (power((x*x)%MOD,n/2))%MOD;
}

int main(){
    int a,b;
    scanf("%d%d%d",&a,&b,&MOD);
    printf("%d^%d mod %d=%lld\n",a,b,MOD,power(a,b));
}
