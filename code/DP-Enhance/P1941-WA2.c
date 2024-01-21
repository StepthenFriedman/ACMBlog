#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define min(x,y) (x)<(y)?(x):(y)
#define max_x 10005
#define max_y 2005
int up[max_x],down[max_x];
int f[max_x][max_y];
int low[max_x],high[max_x];
int n,m,k;
bool turble[max_x];

/*
this solution was adapted from a c++ code.
however it throws up WA.
*/

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&up[i],&down[i]);
        low[i]=1;high[i]=m;
    }
        int a,b,c;
        for(int i=1;i<=k;i++){
            scanf("%d%d%d",&a,&b,&c);
            turble[a]=1;
            low[a]=b+1;
            high[a]=c-1;
        }
        memset(f,0x3f,sizeof(f));
        for(int j=1;j<=m;++j)f[0][j]=0;
        for(int i=1;i<=n;++i){
            for(int j=up[i]+1;j<=m+up[i];++j)
            f[i][j]=min(f[i-1][j-up[i]],f[i][j-up[i]])+1;
            for(int j=m+1;j<=m+up[i];++j)
            f[i][m]=min(f[i][m],f[i][j]);
            for(int j=1;j<=m-down[i];++j)
            f[i][j]=min(f[i][j],f[i-1][j+down[i]]);
            for(int j=1;j<low[i];++j)
            f[i][j]=f[0][0];
            for(int j=high[i]+1;j<=m;++j)
            f[i][j]=f[0][0];
        }
        int res=f[0][0];
        for(int j=1;j<=m;++j)res=min(res,f[n][j]);
        if(res<f[0][0]) printf("1\n%d\n",res);
        else {
            int i,j;
            for(i=n;i>=1;i--){
                for(j=0;j<=m;++j)
                if(f[i][j]<f[0][0])break;
                if(j<=m)break;
            }
            res=0;
            for(int j=1;j<=i;++j){
                if(turble[j])res++;
            }
            printf("0\n%d\n",res);
        }
        return 0;
}