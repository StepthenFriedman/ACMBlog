#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define MAXN 20005
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))

typedef struct ppl{
    ll left,right;
}ppl;

ppl bearu[MAXN];

int cmp(const void *a,const void *b){
    ll la=((ppl*)a)->left,lb=((ppl*)b)->left,
        ra=((ppl*)a)->right,rb=((ppl*)b)->right;
    int res=min(la,rb)-min(lb,ra);
    if (res) return res;
    res=la-lb;
    if (res) return res;
    res=rb-ra;
    return res;
}

int main(){
    //freopen("../../data/P2123.in","r",stdin);
    int T,n,i;
    scanf("%d",&T);
    while (T--){
        scanf("%d",&n);
        for (i=0;i<n;i++){
            scanf("%lld%lld",&bearu[i].left,&bearu[i].right);
        }
        qsort(bearu,n,sizeof(ppl),cmp);
        ll res=bearu[0].left+bearu[0].right;
        ll left=bearu[0].left;
        /*
        for (i=0;i<n;i++){
            printf("%lld %lld\n",bearu[i].left,bearu[i].right);
        }*/
        for (i=1;i<n;i++){
            left+=bearu[i].left;
            res=max(res,left)+bearu[i].right;
        }
        printf("%lld\n",res);
    }
}