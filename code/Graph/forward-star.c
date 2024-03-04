#include <stdio.h>
#include <stdlib.h>
#define MAXN 5000
#define MAXM 200000


typedef struct Edge{
    int next;//pointer to next edge.
    int to;//v in (u,v).
    int w;//weight

}Edge;

int count=0;
int head[MAXM];//the first line of each points.
Edge edge[MAXM];


void add(int u,int v,int w)
{
    edge[count].w = w;
    edge[count].to = v;
    edge[count].next = head[u];
    head[u] = count++;
}

int main(){
    int m,n;
    scanf("%d%d",&n,&m);
    memset(head,-1,m*sizeof(int));
    int u,v,w;
    for (int i=1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);add(v,u,w);
    }
}