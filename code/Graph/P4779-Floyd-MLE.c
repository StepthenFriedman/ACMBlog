#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAXN 100005
#define MAXM 200005
#define ckmin(x,y) (((x)<(y))?(x):((x)=(y)))

int res[MAXN][MAXN]={0};
int edge[MAXN][MAXN]={0};

int main(){
    int m,n,s;
    scanf("%d%d%d",&n,&m,&s);
    int u,v,w;
    for (int i=1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        edge[u][v]=w;
    }
    for (int i=1;i<=n;i++) for (int j=1;j<=n;j++){
        if (i==j) res[i][j]=0;
        else if (edge[i][j]) res[i][j]=edge[i][j];
        else res[i][j]=1000000;
    }
    for (int k=1;k<=n;k++)
        for (int u=1;u<=n;u++)
            for (int v=1;v<=n;v++)
                ckmin(res[u][v],res[u][k]+res[k][v]);
            
    for (int j=1;j<=n;j++) printf("%d ",res[1][j]);
    putchar('\n');
}