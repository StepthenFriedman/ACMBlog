#include <stdio.h>
#include <string.h>
#define MOD 1000000007
#define ll long long
#define LEN 1000005

char ipt[LEN];
int kmp[LEN];
ll realnum;
int num[LEN];

int main(){
    int n,i,j;
    freopen("../../data/P2375.in","r",stdin);
    scanf("%d",&n);
    while (n--){
        scanf("%s",ipt);
        int l=strlen(ipt);
        kmp[0]=0;
        num[0]=0;
        ll ans=1;
        for (i=1;i<l;i++){
            j=kmp[i-1];
            while (j>0 && ipt[i]!=ipt[j]) j=kmp[j-1];
            if (ipt[j]==ipt[i]) {
                kmp[i]=j+1;
                num[i]=num[j]+1;
                realnum=num[i];
                j=kmp[i];
                while (2*j>i+1){
                    realnum--;
                    j=kmp[j-1];
                }
            }
            else{
                kmp[i]=0;
                num[i]=0;
                realnum=0;
            }
            ans=ans*(realnum+1)%MOD;
        }
        printf("%lld\n",ans);
    }
}