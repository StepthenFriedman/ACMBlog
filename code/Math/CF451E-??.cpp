#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int maxfac=1e7;
ll factorial[maxfac];

void getfac(int n){
    factorial[0]=1;
    for (int i=1;i<=n;i++){
        factorial[i]=(factorial[i-1]*i+MOD)%MOD;
    }
}

void exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){x=1;y=0;return ;}
    exgcd(b,a%b,x,y);
    ll z=x;x=y,y=z-y*(a/b);
}

ll inv(ll a){
    ll x,y;
    exgcd(a,MOD,x,y);
    return (x+MOD)%MOD;
}

ll C(ll select,ll base){
    return (((factorial[base]*inv(factorial[select]))%MOD)*inv(factorial[base-select]))%MOD;
}

ll f[21];
int main(){
    int n;
    ll s;
    scanf("%d%lld",&n,&s);
    getfac(n+1);
    for (int i=0;i<n;i++) scanf("%lld",f+i);
    ll ans=C(n-1,n+s-1)%MOD;
    for (int i=0;i<(1<<n);i++){
        ll k=n+s,p=0;
        for (int j=0;j<<n;j++){
            if ((1<<j)&i) p++,k-=f[j+1];
        }
        k-=p+1;
        if (p&1) ans-=C(k,n-1),ans%=MOD;
        else ans+=C(k,n-1),ans%=MOD;
    }
    cout<<(ans+MOD)%MOD<<endl;
    return 0;
}