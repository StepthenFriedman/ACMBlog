#include <stdio.h>
#define MOD 1000000007
//4294967296
long long Fibonacci(unsigned long long n){
    long long f[2]={1,1};
    for (unsigned long long i=0;i<n;i++){
        f[i%2]=(f[0]+f[1])%MOD;
    }
    return f[n%2];
}
long long Fibonacci2(unsigned long long n){
    n-=429496727;
    long long f[2]={41139637,199177269};
    for (unsigned long long i=0;i<n;i++){
        f[i%2]=(f[0]+f[1])%MOD;
    }
    return f[n%2];
}

int main(){
    unsigned long long n;
    scanf("%llu",&n);
    if (n>=429496729){
        printf("%lld\n",Fibonacci2(n-1));
    }
	else printf("%lld\n",Fibonacci(n-1));
	return 0;
}