#include <stdio.h>
#include <stdlib.h>
#define MAXN 100005

int cmp0(const void *a,const void *b){
    return (*(int*)a)-(*(int*)b);
}

int cmp(const void *a,const void *b){
    return (*(int*)b)-(*(int*)a);
}

int main(){
    //freopen("../../data/P1209_5.in","r",stdin);
    int m,s,c,sum;
    scanf("%d%d%d",&m,&s,&c);
    if (m>=c){
        printf("%d\n",c);
        return 0;
    }
    sum=s;
    int last,ipt,arr[c],diff[c],i;
    for (i=0;i<c;i++) scanf("%d",arr+i);
    qsort(arr,c,sizeof(int),cmp0);
    sum-=arr[0]-1;
    for (i=0;i<c-1;i++){
        diff[i]=arr[i+1]-arr[i];
    }
    sum-=s-arr[c-1];
    qsort(diff,c-1,sizeof(int),cmp);
    for (i=0;i<m-1;i++) sum-=diff[i]-1;
    printf("%d\n",sum);
    return 0;
}
