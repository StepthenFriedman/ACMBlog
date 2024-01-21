#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define max(x,y) (x)>(y)?(x):(y)
#define son (tree[i].list[j])
#define LEN 301

typedef struct node{
    int len,score,maxclass,
    *list,dp;
}node;

node tree[LEN];

int dp[LEN][LEN]={0};
int tmp[LEN];
void dfs(int i){
    if (tree[i].dp) return;
    if (tree[i].len==0){
        tree[i].maxclass=1;
        dp[i][1]=tree[i].score;
        tree[i].dp=1;
    }
    else{
        int j,k,l;
        for (j=0;j<tree[i].len;j++){
            dfs(son);
            for (k=1;k<LEN;k++) tmp[k]=INT_MIN;
            for (k=0;k<=tree[i].maxclass;k++){
                for (l=0;l<=tree[son].maxclass;l++){
                    tmp[k+l]=max(tmp[k+l],dp[i][k]+dp[son][l]);
                    if (k+l<=tree[i].maxclass)
                        tmp[k+l]=max(tmp[k+l],dp[i][k+l]);
                    if (k+l<=tree[son].maxclass)
                        tmp[k+l]=max(tmp[k+l],dp[son][k+l]);
                }
            }
            tree[i].maxclass+=tree[son].maxclass;
            for (k=tree[i].maxclass;k>=1;k--){
                dp[i][k]=tmp[k];
            }
        }
        tree[i].maxclass++;
        for (k=tree[i].maxclass-1;k>=0;k--){
            dp[i][k+1]=dp[i][k]+tree[i].score;
        }
        tree[i].dp=1;
    }
}

int main(){
    int m,n,k,s,i;
    scanf("%d%d",&n,&m);
    m++;
    memset(tree,0,sizeof(node)*LEN);
    for (i=0;i<=n;i++){
        tree[i].list=(int*)malloc(m*sizeof(int));
    }
    for (i=1;i<=n;i++){
        scanf("%d%d",&k,&s);
        tree[i].score=s;
        tree[k].list[tree[k].len++]=i;
    }
    dfs(0);
    printf("%d\n",dp[0][m]);
    return 0;
}