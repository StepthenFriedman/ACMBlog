#include <stdio.h>
#define min(x,y) (x)<(y)?(x):(y)
#define maxlen 5000
long long p;

long long f[maxlen][maxlen];

long long C(long long select,long long base){
    if (select<maxlen && base<maxlen && f[select][base]) return f[select][base];
    if (base==1){
        return 1;
    }
    if (select==0){
        return 1;
    }
    if (select==1){
        return base%p;
    }
    if (select<20 && base<20){
        long long ans=1;
        select=min(select,base-select);
        int i;
        for (i=0;i<select;i++){
            ans*=base-i;
        }
        for (i=0;i<select;i++){
            ans/=select-i;
        }
        ans%=p;
        f[select][base]=ans;
        return ans;
    }
    long long ans=(C(select/p,base/p)*C(select%p,base%p))%p;
    if (select<maxlen && base<maxlen) f[select][base]=ans;
    return ans;
}

int main(){
    int T;
    long long m,n,base,select;
    scanf("%d",&T);
    while (T--){
        memset(f,0,sizeof(int)*min(maxlen,(m+n)));
        scanf("%lld%lld%lld",&m,&n,&p);
        base=m+n;
        select=min(m,n);
        printf("%lld\n",C(select,base));
    }
}