#include<stdio.h>
#include<string.h>
#define max(x,y) (x)>(y)?(x):(y)
int dp[1000000];
/*
in some cases, t was too large and m is only 1.
*/
int main(){
    int t,m, i=1,j=t;
    while(~scanf("%d%d",&t,&m)){
    	int c,v;
		if (m==1) {
			scanf("%d%d",&c,&v);
			printf("%lld\n",(long long)v*((long long)t/c));
			continue;
		}
		memset(dp,0,t*sizeof(int));
    	for(i=1;i<=m;i++){  
    		scanf("%d%d",&c,&v);
    	    for(j=c;j<=t;j++){
				dp[j]=max(dp[j],dp[j-c]+v);
    	    }
	    }
	    printf("%d\n",dp[t]);
	}
    return 0;
}
