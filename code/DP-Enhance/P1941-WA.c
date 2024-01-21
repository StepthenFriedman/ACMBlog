#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define M 1000
#define N 10000
#define min(x,y) (x)<(y)?(x):(y)

typedef struct pipe{
    int x,h,l;
}pp;

int x[N],y[N];
int map[2][M]={0};
int count[2][M]={0};
pp pip[N];

/*
1: x:3 y:9 0 0 0 1 1 1 1 0 0 0 0 
2: x:9 y:9 0 0 0 0 0 0 0 0 0 0 1 
3: x:1 y:2 0 0 0 0 0 0 0 0 1 0 1 
4: x:1 y:3 0 0 0 0 0 1 0 1 0 1 1 
5: x:1 y:2 0 0 0 1 0 0 0 0 0 0 0 
6: x:1 y:1 0 0 0 0 1 0 0 0 0 0 0 
7: x:2 y:1 0 0 0 0 0 0 1 0 0 0 0 
8: x:2 y:1 0 0 0 0 0 0 0 0 1 0 0 
9: x:1 y:6 0 0 1 0 0 0 0 0 0 0 0 
*/

int cmp(const void* a,const void* b){
    return ((pp*)a)->x-((pp*)b)->x;
}

int main(){
    int n,m,k,i,j,ki;
    scanf("%d%d%d",&n,&m,&k);
    x[0]=y[0]=1;
    for (i=0;i<n;i++) scanf("%d%d",x+1+i,y+1+i);
    for (i=0;i<k;i++) {
        scanf("%d%d%d",&(pip[i].x),&(pip[i].l),&(pip[i].h));
    }
    qsort(pip,k,sizeof(pp),cmp);
    
    ki=0;
    int pass;
    for (i=0;i<m;i++) map[0][i]=1,count[0][i]=0;
    for (i=1;i<=n;i++){
        pass=0;
        memset(map[i%2],0,M*sizeof(int));
        for (j=0;j<=m;j++)
            count[i%2][j]=INT_MAX;
        /*
        if (i==1){
            for (int j2=0;j2<=m;j2++) if (count[0][j2]==INT_MAX) printf("-1 "); else printf("%2d ",count[0][j2]);putchar('\n');
        }*/
        for (j=0;j<=m;j++){
            if (map[!(i%2)][j]==1){
                if (j>y[i]) {
                    map[i%2][j-y[i]]=1;
                    count[i%2][j-y[i]]=min(count[i%2][j-y[i]],count[!(i%2)][j]);
                }
                int ji;
                for (ji=1;j+ji*x[i]<m;ji++){
                    map[i%2][j+ji*x[i]]=1;
                    count[i%2][j+ji*x[i]]=min(count[i%2][j+ji*x[i]],count[!(i%2)][j]+ji);
                }
                map[i%2][m]=1;
                count[i%2][m]=count[!(i%2)][j]+ji;
            }
        }
        if (ki<k && pip[ki].x==i){
            for (j=m;j>=pip[ki].h;j--) map[i%2][j]=0;
            for (j=pip[ki].l;j>=0;j--) map[i%2][j]=0;
            ki++;
        }
        //printf("%d: x:%d y:%d\n",i,x[i],y[i]);
        //for (j=0;j<=m;j++) printf("%2d ",map[i%2][j]);putchar('\n');
        //for (j=0;j<=m;j++) if (count[i%2][j]==INT_MAX) printf("-1 "); else printf("%2d ",count[i%2][j]);putchar('\n');
        for (j=0;j<=m;j++)
            if (map[i%2][j]==1)
                pass=1;
        if (!pass) goto end;
    }
    end:
    if (!pass) printf("0\n%d\n",ki-1);
    else {
        int minTap=INT_MAX;
        for (i=1;i<=m;i++) if (map[n%2][i]) {
            minTap=min(minTap,count[n%2][i]);
        }
        printf("1\n%d\n",minTap);
    }
}