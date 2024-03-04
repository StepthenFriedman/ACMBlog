#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 105
#define MAXM 10005
#define LARGE 1000000001
#define ckmin(x,y) ((x)<(y)?(x):(x=y))

typedef struct Edge{
    int next,to,w;
}Edge;

int count=0;
int head[MAXM]={[0 ... MAXM-1]=-1};
Edge edge[MAXM];

int res[MAXN][MAXN];
char itered[MAXN][MAXN]={0};

void add(int u,int v,int w)
{
    edge[count].w = w;
    edge[count].to = v;
    edge[count].next = head[u];
    head[u] = count++;
}

int n;

void dijkstra(){
    for (int i=0;i<=n;i++) for (int j=0;j<=n;j++){
        if (i==j) res[i][j]=0;
        else res[i][j]=LARGE;
    }
    for (int l=1;l<=n;l++){
        for (int t=1;t<=n;t++){
            int indx=0;
            for (int i=1;i<=n;i++) if ((!itered[l][i]) && res[l][indx]>res[l][i]){
                indx=i;
            }
            itered[l][indx]=1;
            for (int i=head[indx];~i;i=edge[i].next){
                ckmin(res[l][edge[i].to],res[l][indx]+edge[i].w);
            }
        }
    }
}

int main(){
    int m,s;
    scanf("%d%d",&n,&m);
    int u,v,w;
    for (int i=1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);add(v,u,w);
    }
    dijkstra();
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++) printf("%d ",res[i][j]);
        putchar('\n');
    }
}
