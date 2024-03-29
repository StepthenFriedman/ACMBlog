#include <stdio.h>
#include <stdlib.h>
#define max(x,y) x>y?x:y
#define LEN 7000

typedef struct node{
    long long r,len;
    int maxlen;
    struct node** list;
    long long rsp,rsa;
}node;

node *list[LEN];
long long slaves[LEN]={0};

long long dfs(node* mst,int headPresent){
    int i;
    long long present=0,absent=0;
    if (headPresent==0) {
        if (mst->rsp) {
            present=mst->rsp;
            goto next1;
        }
        present+=mst->r;
        if (mst->len==0) return mst->rsp=present;
        for (i=0;i<mst->len;i++){
            present+=dfs(mst->list[i],1);
        }
        mst->rsp=present;
    }
    next1:
    if (mst->rsp) {
        absent=mst->rsa;
        goto next2;
    }
    for (i=0;i<mst->len;i++){
        absent+=dfs(mst->list[i],0);
    }
    mst->rsa=absent;
    next2:
    return max(absent,present);
}

int main(){
    int n,i,ipt,ipt2;
    scanf("%d",&n);
    for (i=0;i<n;i++) {
        scanf("%d",&ipt);
        node *tmpn=(node*)malloc(sizeof(node));
        tmpn->r=ipt;
        tmpn->len=0;
        tmpn->rsp=tmpn->rsa=0;
        tmpn->maxlen=100;
        node **tmpl=(node**)malloc(sizeof(node*)*100);
        tmpn->list=tmpl;
        list[i]=tmpn;
    }
    for (i=0;i<n-1;i++){
        scanf("%d%d",&ipt,&ipt2);
        node* master=list[ipt2-1];
        node* slave=list[ipt-1];
        master->list[master->len++]=slave;
        if (master->len>=master->maxlen-1) {
            master->maxlen+=1000;
            master->list=(node**)realloc(master->list,master->maxlen*sizeof(node*));
        }
        slaves[ipt-1]=1;
    }
    node* master;
    for (i=0;i<n;i++){
        if (slaves[i]==0){
            master=list[i];
            break;
        }
    }
    printf("%lld\n",dfs(master,0));
}