#include <stdio.h>
#include <limits.h>
#define MOD 100003ULL
#define BIT 9223372036854775808ULL

/*
the recursion depth is too large.
for samples over 10000 it raises stack overflow.
however it offers a solution within 100.
we're going to find the routine with it.
*/

unsigned long long findSteps(unsigned long long n,unsigned long long k){
    if (n>k){
        unsigned long long ans=0,i;
        for (i=1;i<=k;i++){
            ans+=findSteps(n-i,k);
            ans%=MOD;
        }
        return ans%MOD;
    }else{
        unsigned long long ans=1;
        while (n>63) {
            ans*=BIT%MOD;
            ans%=MOD;
            n-=63;
        }
        return ans*(1ULL<<(n-1))%100003;
    }
}

void findRoutine(){
    for (int k=1;k<20;k++) {
        for (int n=1;n<20;n++) {
            printf("%3lld ",findSteps(n,k));
        }
        putchar('\n');
    }
}

/*
1   1   1   1   1   1   1   1   1 
1   2   3   5   8  13  21  34  55 
1   2   4   7  13  24  44  81 149 
1   2   4   8  15  29  56 108 208 
1   2   4   8  16  31  61 120 236 
1   2   4   8  16  32  63 125 248 
1   2   4   8  16  32  64 127 253 
1   2   4   8  16  32  64 128 255 
1   2   4   8  16  32  64 128 256 
*/

int main(){
    unsigned long long n,k;
    while (~scanf("%llu%llu",&n,&k)){
        printf("%llu\n",findSteps(n,k));
    }
}