#include <stdio.h>
#include <string.h>
#define max(x,y) (x)>(y)?(x):(y)

int f[50][50][50][50]={0};
int map[50][50]={0};
int m,n;
int dfs(int x1,int y1,int x2,int y2){
    if (x1==m-1 && y1==n-2 && x2==m-2 && y2==n-1) return map[x1][y1]+map[x2][y2];
    if (f[x1][y1][x2][y2]) return f[x1][y1][x2][y2];
    int res=0;
    if (!(x1==x2+1 && y2==y1+1)){
        res=max(res,dfs(x1,y1+1,x2+1,y2));
    }
    if (x1<m-1&&x2<m-2){
        res=max(res,dfs(x1+1,y1,x2+1,y2));
    }
    if (y1<n-2&&y2<n-1){
        res=max(res,dfs(x1,y1+1,x2,y2+1));
    }
    if (x1<m-1&&y2<n-1){
        res=max(res,dfs(x1+1,y1,x2,y2+1));
    }
    res+=map[x1][y1]+map[x2][y2];
    return f[x1][y1][x2][y2]=res;
}

int main(){
    int i,j;
    scanf("%d%d",&m,&n);
    for (i=0;i<m;i++) for (j=0;j<n;j++) scanf("%d",&map[i][j]);
    printf("%d\n",dfs(1,0,0,1));
}