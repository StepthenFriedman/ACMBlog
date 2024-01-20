#include <stdio.h>
#include <string.h>

unsigned long long max(unsigned long long x,unsigned long long y){
    return (x>y)?x:y;
}

int main(){
    int n,i,j;
    while (~scanf("%d",&n)){
        unsigned long long arr[2][n],ans=0,ipt;
        memset(arr,0,2*n*sizeof(unsigned long long));
        for (i=0;i<n;i++){
            for (j=0;j<=i;j++){
                scanf("%llu",&ipt);
                if (j==i)       arr[(i%2)][j]=ipt+arr[!(i%2)][j-1];
                else if (j==0)  arr[(i%2)][j]=ipt+arr[!(i%2)][j];
                else            arr[(i%2)][j]=ipt+max( arr[!(i%2)][j],arr[!(i%2)][j-1]);
            }
        }
        for (j=0;j<n;j++){
            ans=max(ans,arr[(n-1)%2][j]);
        }
        printf("%llu\n",ans);
    }
}