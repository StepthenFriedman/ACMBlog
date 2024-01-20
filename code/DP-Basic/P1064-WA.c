#include <stdio.h>
#include <string.h>
#define max(x,y) x>y?x:y
#define maxn 32005
/*
wrong decipher of the problem.
*/
int dp[maxn]={0};
int main(){
    int n,m,i,j;
    while (~scanf("%d%d",&n,&m)){

        int v,p,q;
        memset(dp,0,(n+1)*sizeof(int));
        int v1,w1,v2=-1,w2,v3=-1,w3,v4=-1,w4;
        scanf("%d%d%d",&v,&p,&q);
        for (i=0;i<m;i++){
            if (q==0){
                if (i!=0){
                    for(j=n;j>=v1;j--){
                        dp[j] = max(dp[j],dp[j-v1]+w1);
                        if ((~v2)&&(j>=v2)) dp[j] = max(dp[j],dp[j-v2]+w2);
                        if ((~v3)&&(j>=v3)) dp[j] = max(dp[j],dp[j-v3]+w3);
                        if ((~v4)&&(j>=v4)) dp[j] = max(dp[j],dp[j-v4]+w4);
                    }
                    v2=v3=v4=-1;
                    for (j=0;j<=n;j++) printf("%2d ",dp[j]); putchar('\n');
                }
                v1=v,w1=p*v;
                if (i<m-1) scanf("%d%d%d",&v,&p,&q);
            }
            else{
                v2=v+v1;
                w2=p*v+w1;
                if (i<m-1) scanf("%d%d%d",&v,&p,&q),i++;
                else break;
                if (q==0) {
                    v3=v4=-1;
                    continue;
                }
                v3=v+v1;
                w3=p*v+w1;
                v4=v+v2;
                w4=p*v+w2;
                if (i<m-1) scanf("%d%d%d",&v,&p,&q);
            }
        }
        for(j=n;j>=v1;j--){
            dp[j] = max(dp[j],dp[j-v1]+w1);
            if ((~v2)&&(j>=v2)) dp[j] = max(dp[j],dp[j-v2]+w2);
            if ((~v3)&&(j>=v3)) dp[j] = max(dp[j],dp[j-v3]+w3);
            if ((~v4)&&(j>=v4)) dp[j] = max(dp[j],dp[j-v4]+w4);
        }
        for (j=0;j<=n;j++) printf("%2d ",dp[j]); putchar('\n');
        printf("%d\n",dp[n-1]);
    }
    return 0;
}