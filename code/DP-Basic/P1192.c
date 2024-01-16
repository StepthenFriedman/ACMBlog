#include <stdio.h>

unsigned long long findSteps(unsigned long long n,unsigned long long k){
    if (n>k){
        unsigned long long ans=0;
        for (int i=1;i<=k;i++){
            ans+=findSteps(n-i,k);
        }
        return ans%100003;
    }else{
        return (1ULL<<(n-1))%100003;
    }
}

int main(){
    unsigned long long n,k,ans;
    while (~scanf("%llu%llu",&n,&k)){
        printf("%llu\n",findSteps(n,k));
    }
}