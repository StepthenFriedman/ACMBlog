#include <stdio.h>

#define mod 1000000007
#define maxn 600000
typedef long long ll;
ll f[maxn];
ll n, k;

ll ksm(ll a, ll b){
    ll res = 1;
    while(b){
        if(b % 2)
            res = (res * a) % mod;
        b /= 2;
        a = (a * a) % mod;
    }
    return res % mod;
}

int main()
{
    f[0] = 1;
    for(int i = 1; i <= 500000; i++)
        f[i] = f[i-1] * 2ll % mod;
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld",&n,&k);
        ll ans = 0;
        for(ll i = k-1; i >= 0; i--){
            if(n % 2 == 0) ans += ksm(2, n*i) * ksm(f[n-1]-1, k-1-i);
            ans %= mod;
        }
        if(n % 2 == 0) ans += ksm((f[n-1]-1)%mod, k);
        else ans += ksm((f[n-1]+1)%mod, k);
        ans %= mod;
        printf("%lld\n", ans);
    }
    return 0;
}