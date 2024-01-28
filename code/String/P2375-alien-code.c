#include <stdio.h>
#include <string.h>
#define ll long long
#define MOD 1000000007
int n,fail[1000010],ans[1000010];ll cnt;char a[1000010];
int main(){
    int T,i,j;scanf("%d",&T);
    while(T--){
        scanf("%s",a);n=strlen(a);
        memset(fail,0,sizeof(fail));
        j=0;ans[0]=0;ans[1]=1;
        
        for(i=1;i<n;i++){//求解next
            while(j&&(a[i]!=a[j])) j=fail[j];
            j+=(a[i]==a[j]);fail[i+1]=j;ans[i+1]=ans[j]+1;//递推记录ans
        }
        
        j=0;cnt=1;
        /*
        could't understand.
        */
        for(i=1;i<n;i++){//求解num
            while(j&&(a[i]!=a[j])) j=fail[j];
            j+=(a[i]==a[j]);
            while((j<<1)>(i+1)) j=fail[j];
            cnt=(cnt*(ll)(ans[j]+1))%MOD;//记得+1
        }
        printf("%lld\n",cnt);
    }
}