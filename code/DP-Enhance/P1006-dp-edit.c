#include <stdio.h>
#include <string.h>
#define max(x,y) (x)>(y)?(x):(y)

int main(){
    int m,n,i,j,t;
    scanf("%d%d",&m,&n);
    int map[m][n],dpup[m+1][n+1],dpdown[m+1][n+1];
    memset(dpup,0,(m+1)*(n+1)*sizeof(int));
    memset(dpdown,0,(m+1)*(n+1)*sizeof(int));
    for (i=0;i<m;i++) for (j=0;j<n;j++) scanf("%d",&map[i][j]);
    
    int x1=1,y1=0,x2=0,y2=1,res=map[0][1]+map[1][0];
    t=m+n-4;
    while (t--){
        if (x1==x2+1 && y2==y1+1){
            memset(dpdown,0,(m+1)*(n+1)*sizeof(int));
            for (i=x1;i<m-1;i++){
                for (j=y2;j<n;j++){
                    dpdown[i][j]=max(dp[i-1][j],dp[i][j-1])+map[i][j];
                }
            }
        }else{

        }
    }
}