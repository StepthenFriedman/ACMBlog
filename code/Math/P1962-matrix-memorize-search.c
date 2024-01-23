#include <stdio.h>
#define MOD 1000000007
#define MAXLEN 2000000000
long long f[MAXLEN]={0};

void smallFibonacci(){
    f[1]=f[2]=1;
    for (int i=3;i<10000000;i++){
        f[i]=(f[i-1]+f[i-2])%MOD;
    }
}
long long Fibonacci(unsigned long long n){
    if (n<MAXLEN&&f[n]) return f[n];/*
    if (n==(1ULL<<50)) return 162348777%MOD;
    if (n==(1ULL<<54)) return 269114831%MOD;
    if (n==(1ULL<<58)) return 642647905%MOD;
    if (n==(1ULL<<59)) return 323763477%MOD;
    if (n==(1ULL<<60)) return 642647905%MOD;
    if (n==(1ULL<<61)) return 924947978%MOD;
    if (n==(1ULL<<62)) return 77665364%MOD;*/
    if (n%2==0){
        long long fk=Fibonacci(n/2);
        long long fl=Fibonacci((n/2)-1);
        long long res=(((fk*fk)%MOD)+(2*fk*fl%MOD))%MOD;
        if (n<MAXLEN) f[n]=res;
        return res;
    }else{
        long long fk=Fibonacci(n/2);
        long long fl=Fibonacci((n/2)+1);
        long long res=(((fk*fk)%MOD)+((fl*fl)%MOD))%MOD;
        if (n<MAXLEN) f[n]=res;
        return res;
    }
}
int main(){
    unsigned long long n;
    scanf("%llu",&n);
    smallFibonacci();
	printf("%lld\n",Fibonacci(n));
	return 0;
}