#include <stdio.h>
#include <stdlib.h>
#define MAXN 5005
#define MAXM 200005


typedef struct Edge{
    int u,v,w;
}Edge;
Edge edge[MAXM];

int cmp(const void *a,const void *b){return ((Edge*)a)->w-((Edge*)b)->w;}

int m,n;
int father[MAXN];

int find(int x)
{
    return father[x]==x?x:(father[x]=find(father[x]));
}

void kruskal()
{
    qsort(edge+1,m,sizeof(Edge),cmp);
    int count=0,ans=0;
    for(int i=1;i<=m;i++)
    {
        int u=find(edge[i].u), v=find(edge[i].v);

        if(u==v) continue;//check whether if 2 points is joint.

        ans+=edge[i].w;//choose the edge.

        father[v]=u;//connect u,v.

        if(++count==n-1) break;//check whether lines is enough.
    }
    if (count<n-1) printf("orz\n");
    else printf("%d\n",ans);
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) father[i]=i;
    for (int i=1;i<=m;i++){
        scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
    }
    kruskal();
    return 0;
}