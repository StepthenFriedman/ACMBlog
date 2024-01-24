#include <stdio.h>
#define min(x,y) (x)<(y)?(x):(y)
#define MOD 1000000007
#define LEN 200005
#define ll long long

ll fac[LEN];
void init(ll n) {
	fac[0]=1;
	for (ll i=1; i<=n; i++)
		fac[i]=fac[i-1]*i%MOD;
}
ll quick_pow(ll a, ll k) {
	ll res=1;
	a%=MOD;
	while (k) {
		if (k&1) res=res*a%MOD;
		a=a*a%MOD;
		k>>=1;
	}
	return res;
}
ll inv(ll x) {return quick_pow(x,MOD-2);}

ll getC(ll n, ll m) {
    return fac[n]*inv(fac[n-m]*fac[m]%MOD)%MOD;
}

ll count00(ll n){
    ll i,ans=0;
    for (i=2;i<n;i+=2){
        ans=(ans+getC(i,n))%MOD;
    }
    return ans;
}

ll npower2(ll n){
    ll ans=1;
    while (n--){
        ans<<=1;
        ans%=MOD;
    }
    return ans;
}

int main(){
    ll t,n,k;
    scanf("%lld",&t);
    while (t--){
        scanf("%lld%lld",&n,&k);

        ll count0=count00(n);
        ll power2=npower2(n);
        ll ans=1;
        if ((n%2)==1){
            ll count1=1;
            for (ll ki=1;ki<k;ki++){
                ans;
            }
        }
        else{

        }
    }

}