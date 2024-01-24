#include <stdio.h>
#define MAXLEN 40005

long long p[MAXLEN];

void Euler(int n){
    int i,j;
    for (i=1;i<=n;i++){
        p[i]=i;
    }
    for (i=2;i<=n;i++){
        if (p[i]==i){
            for (j=i;j<=n;j+=i){
                p[j]-=p[j]/i;
            }
        }
    }
}

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
    Euler(n);
    for (i=2;i<n;i++){
        ans+=p[i];
    }
    ans=ans*2+3;
    printf("%lld\n",ans);
}