#include <stdio.h>
#include <stdlib.h>
#define ll long long

/*
long long is not enough.
*/


typedef struct ppl{
    int left,right,plus;
}ppl;

int cmp(const void *a,const void *b){
    ppl *ap=(ppl*)a,*bp=(ppl*)b;
    return (bp->plus)-(ap->plus);
}

int main(){
    freopen("../../data/P1080.in","r",stdin);
    int n,i,j;
    ll l,r,ans;
    scanf("%d%lld%d",&n,&ans,&i);
    ppl arr[n];
    for (i=0;i<n;i++){
        scanf("%lld%lld",&l,&r);
        ans*=l;
        arr[i].left=l,arr[i].right=r;
        arr[i].plus=l*r;
    }
    qsort(arr,n,sizeof(ppl),cmp);
    j=0;
    while (arr[j].plus>ans && j<n){
        ans/=arr[j].left;
        j++;
    }
    if (j==n-1) printf("0\n");
    else printf("%lld\n",ans/arr[j].plus);
    return 0;
}