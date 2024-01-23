#include <stdio.h>
#define maxn 3000000

long long inv[maxn];
void inverse(long long n, long long p){
    inv[1] = 1;
    for(int i = 2; i <= n; ++i)
    inv[i] = (p - p/i) * inv[p % i] % p;
}

int main(){
    long long i,n,p;
    scanf("%lld%lld",&n,&p);
    inverse(n,p);
    for (i=1;i<=n;i++){
        printf("%lld\n",inv[i]);
    }
}