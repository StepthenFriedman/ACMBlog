#include<stdio.h>
#include<limits.h>
#define min(x,y) (x)<(y)?(x):(y)

int f[600][600]={0};

int ipt[10000]={0};

int dfs(int start,int end){
    if (f[start][end]) return f[start][end];
    int res=INT_MAX;
    
}

int exit[10000][300]={0};
int kill[10000]={0};

int main(){
    int T,n,a[300],b[300],d[300],i,j,k;
    scanf("%d",&T);
    while (T--){
        scanf("%d",&n);
        for (i=0;i<n;i++) scanf("%d%d%d",a+i,b+i,d+i);
        ipt[a[i]]=ipt[b[i]]=1;
        for (j=a[i];j<b[i];j++){
            for (k=0;exit[j][k]!=0;k++);
            exit[j][k]=d[i];
            
        }
    }
}