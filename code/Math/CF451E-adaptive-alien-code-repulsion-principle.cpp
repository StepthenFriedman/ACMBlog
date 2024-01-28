#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL long long
#define ll long long
const LL mod=1e9+7;
const LL p=1e9+7;
void exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){x=1;y=0;return ;}
    exgcd(b,a%b,x,y);
    ll z=x;x=y,y=z-y*(a/b);
}

ll inv(ll a){
    ll x,y;
    exgcd(a,p,x,y);
    return (x+p)%p;
}

ll C(ll n,ll m){
	if(n<m) return 0;
	if(m>n-m) m=n-m;
	ll a=1,b=1;
	for(int i=0;i<m;i++){
		a=(a*(n-i))%p;
		b=(b*(i+1))%p;
	}
    ll revb=inv(b);
	return (a*revb)%p;
}
ll Lucas(ll n,ll m){
	if(m==0) return 1;
	return Lucas(n/p,m/p)*C(n%p,m%p)%p;
}
LL f[21];
LL solve(int n,LL s) {
	LL res=0;
	for (int i=0;i<(1<<n);i++) {
		LL cnt=s;int del=1;
		for (int j=1;j<=n;j++)
			if (i&(1<<(j-1))) 
				cnt-=f[j]+1,del=-del;
		if (cnt<0) continue;
		res=(res+Lucas(cnt+n-1,n-1)*(LL)del)%mod;
	}
	return (res+mod)%mod;
}
int main() {
	int n;LL s;
	while (~scanf("%d%lld",&n,&s)) {
		for (int i=1;i<=n;i++) scanf("%lld",&f[i]);
		printf("%lld\n",solve(n,s));
	}
}