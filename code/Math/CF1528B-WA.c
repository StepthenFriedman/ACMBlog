#include <stdio.h>
#define ll long long
#define LEN 1000000
#define MOD 998244353

ll map[LEN]={0};
ll exist[LEN]={0};

/*fail on sample "7".
why?
*/


ll solve(int n){
    if (exist[n]) return map[n];
    if (n%2) return 0;
    ll ans=0;
    int i,j;
    for (i=2;i*i<=n;i++){
        if (n%i==0){
            ans++;
            j=n/i;
            if (j>i && j%2==0) ans++;
            ans%=MOD;
        }
    }
    if (n==14) printf(">>%lld\n",ans);
    for (i=0;i<=n-2;i+=2){
        if (n==14) printf(">>f(%d):%lld\n",i,solve(i));
        ans=(ans+solve(i))%MOD;
        printf("%lld\n",ans);
    }
    exist[n]=1;
    return map[n]=ans;
}

int main(){
    int n;
    map[0]=1,map[1]=0,map[2]=1;
    exist[0]=exist[1]=exist[2]=1;
    scanf("%d",&n);
    printf("%lld\n",solve(2*n));
}