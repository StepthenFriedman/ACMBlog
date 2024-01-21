#include <stdio.h>
#include <limits.h>
#define MOD 100003
#define BIT 4611686018427387904
#define LEN 1000005

int arr[LEN]={0};

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
        arr[n]=(2*findSteps(n-1,k)+MOD)%MOD;
        return arr[n];
    }
}

int main(){
    int n,k;
    arr[0]=arr[1]=1;
    scanf("%d%d",&n,&k);
    printf("%d\n",findSteps(n,k));
}