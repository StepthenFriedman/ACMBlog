#include <stdio.h>
#include <limits.h>
#define MOD 100003
#define BIT 4611686018427387904
#define LEN 1000005

int arr[LEN]={0};

long long power(long long x,int n){
    if (n<2) return x%MOD;
    else if (n%2) return ((power(x,n-1)%MOD)*x)%MOD;
    else return (power((x*x)%MOD,n/2))%MOD;
}

int findSteps(int n,int k){
    if (arr[n]) return arr[n];
    if (n>k){
        int ans=0,i;
        for (i=1;i<=k;i++){
            ans+=findSteps(n-i,k);
            ans%=MOD;
        }
        arr[n]=(ans+MOD)%MOD;
        return arr[n];
    }else{
        arr[n]=power(2,n-1);
        return arr[n];
    }
}

int main(){
    int n,k;
    arr[0]=arr[1]=1;
    scanf("%d%d",&n,&k);
    printf("%d\n",findSteps(n,k));
}