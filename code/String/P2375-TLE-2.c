#include <stdio.h>
#include <string.h>
#define MOD 1000000007
#define ll long long
#define LEN 1000005

char ipt[LEN];
int kmp[LEN];

int main(){
    int n,i,j;
    //freopen("../../data/P2375.in","r",stdin);
    scanf("%d",&n);
    while (n--){
        scanf("%s",ipt);
        int l=strlen(ipt);
        ll ans=1,num=0;
        kmp[0]=0;
        for (i=1;i<l;i++){
            num=0;
            j=kmp[i-1];
            while (j>0 && ipt[i]!=ipt[j]) j=kmp[j-1];
            if (ipt[j]==ipt[i]) j++;
            kmp[i]=j;
            while (j>0){
                if (2*j<=i+1) num++;
                j=kmp[j-1];
            }
            ans=ans*(num+1)%MOD;
        }
        printf("%lld\n",ans);
    }
}