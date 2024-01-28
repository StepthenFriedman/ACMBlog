#include <stdio.h>
#include <string.h>
#define MOD 1000000007
#define ll long long
#define LEN 1000005

char ipt[LEN];
int kmp[LEN];
ll realnum;
int num[LEN];//the number of qualified substring that might be overlapping.

int main(){
    int n,i,j;
    //freopen("../../data/P2375.in","r",stdin);
    scanf("%d",&n);
    while (n--){
        scanf("%s",ipt);
        int l=strlen(ipt);
        memset(num,0,sizeof(int)*(l+1));
        kmp[0]=0;
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
            
            /*
            while (j>0){
                j=kmp[j-1];
            }*/
            ans=ans*(realnum+1)%MOD;
        }
        /*
        for (i=0;i<l;i++){
            printf("%d ",kmp[i]);
        }putchar('\n');

        for (i=0;i<l;i++){
            printf("%d ",num[i]);
        }putchar('\n');
*/
        printf("%lld\n",ans);
    }
}