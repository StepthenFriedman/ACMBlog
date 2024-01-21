#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define max(x,y) (x)>(y)?(x):(y)
#define son (tree[i].list[j])
#define LEN 3001

typedef struct node{
    int len,earn,maxppl,
    *list,dp;
}node;

node tree[LEN];

int dp[LEN][LEN]={0};
int tmp[LEN];
void dfs(int i){
    if (tree[i].dp) return;
    if (tree[i].len==0){
        dp[i][1]=tree[i].earn;
        tree[i].dp=1;
    }
    else{
        int j,k,l;
        for (j=0;j<tree[i].len;j++){
            dfs(son);
            for (k=1;k<LEN;k++) tmp[k]=INT_MIN;
            for (k=0;k<=tree[i].maxppl;k++){
                for (l=0;l<=tree[son].maxppl;l++){
                    tmp[k+l]=max(tmp[k+l],dp[i][k]+dp[son][l]);
                    if (k+l<=tree[i].maxppl)
                        tmp[k+l]=max(tmp[k+l],dp[i][k+l]);
                    if (k+l<=tree[son].maxppl)
                        tmp[k+l]=max(tmp[k+l],dp[son][k+l]);
                }
            }
            tree[i].maxppl+=tree[son].maxppl;
            for (k=tree[i].maxppl;k>=1;k--){
                dp[i][k]=tmp[k];
            }
        }
        tree[i].dp=1;
        for (k=1;k<=tree[i].maxppl;k++){
            dp[i][k]+=tree[i].earn;
        }
    }
}

int main(){
    int m,n,k,i,j,A,C;
    scanf("%d%d",&n,&m);
    memset(tree,0,sizeof(node)*LEN);
    for (i=0;i<n-m;i++){
        scanf("%d",&k);
        tree[i].len=k;
        tree[i].list=(int*)malloc(k*sizeof(int));
        tree[i].dp=0;
        tree[i].maxppl=0;
        for (j=0;j<k;j++){
            scanf("%d%d",&A,&C);
            A--;
            tree[A].earn-=C;
            (tree[i].list)[j]=A;
        }
    }
    for (;i<n;i++){
        scanf("%d",&C);
        tree[i].len=0;
        tree[i].earn+=C;
        tree[i].dp=0;
        tree[i].maxppl=1;
    }
    dfs(0);
    int res=0;
    for (i=1;i<=tree[0].maxppl;i++) {
        if (dp[0][i]>=0) res=i;
    }
    printf("%d\n",res);
    return 0;
}