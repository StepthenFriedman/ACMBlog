#include <stdio.h>
#define getmin(a,i) (((a)<(i))?(0):(a=i))
#define getmax(a,i) (((a)>(i))?(0):(a=i))
#define min(x,y) (((x)<(y))?(x):(y))
#define max(x,y) (((x)>(y))?(x):(y))

int main(){
    //freopen("../../data/P1007.in","r",stdin);
    int L,N,i,res1=0,res2=0;
    scanf("%d%d",&L,&N);
    int arr[N];
    for (i=0;i<N;i++){
        scanf("%d",arr+i);
        getmax(res1,min((L-arr[i]+1),arr[i]));
        getmax(res2,max((L-arr[i]+1),arr[i]));
    }
    printf("%d %d\n",res1,res2);
}