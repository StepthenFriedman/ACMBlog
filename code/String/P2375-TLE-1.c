#include <stdio.h>
#include <string.h>
#define MOD 1000000007
#define ll long long
#define LEN 1000005

char ipt[LEN];
int kmp[LEN];
int num[LEN];

int main(){
    int n,i,j;
    //freopen("../../data/P2375.in","r",stdin);
    scanf("%d",&n);
    while (n--){
        scanf("%s",ipt);
        int l=strlen(ipt);
        memset(num,0,sizeof(int)*(l+1));
        kmp[0]=0;
        for (i=1;i<l;i++){
            j=kmp[i-1];
            while (j>0 && ipt[i]!=ipt[j]) j=kmp[j-1];
            if (ipt[j]==ipt[i]) j++;
            kmp[i]=j;
            while (j>0){
                if (2*j<=i+1) num[i]++;
                j=kmp[j-1];
            }
        }
        /*
        for (i=0;i<l;i++){
            printf("%d ",kmp[i]);
        }putchar('\n');*/
        ll ans=1;
        for (i=0;i<l;i++){
            ans=ans*(num[i]+1)%MOD;
            //printf("%d ",num[i]);
        }//putchar('\n');
        printf("%lld\n",ans);
    }
}