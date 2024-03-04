#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAXN 105
#define MAXM 10005
#define ckmin(x,y) (((x)<(y))?(x):((x)=(y)))

int res[MAXN][MAXN]={0};
int edge[MAXN][MAXN]={0};

/*
for k := 1 to n:
  for u := 1 to n:
    for v := 1 to n:
      g(u,v) := min{g(u,v), g(u,k)+g(k,v)}
*/

int main(){
    int m,n;
    scanf("%d%d",&n,&m);
    int u,v,w;
    for (int i=1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        edge[u][v]=edge[v][u]=w;
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
            
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++) printf("%d ",res[i][j]);
        putchar('\n');
    }
}