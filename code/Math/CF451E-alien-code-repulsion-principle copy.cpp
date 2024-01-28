#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL long long
const LL mod=1e9+7;
LL Pow(LL x,LL y) {
	LL res=1;
	while (y) {
		if (y&1) res=res*x%mod;
		x=x*x%mod,y>>=1;
	}
	return res;
}
LL C(int n,int r) {
	if (n<r) return 0;
	r=min(r,n-r);
	LL res=1,a=1,b=1;
	for (int i=1;i<=r;i++)
		a=a*(n-i+1)%mod,b=b*i%mod;
	res=res*a%mod*Pow(b,mod-2)%mod;
	return res;
}
LL Lucas(LL a,LL b) {
	if (a<=mod&&b<=mod) return C(a,b);
	return C(a%mod,b%mod)*Lucas(a/mod,b/mod)%mod;
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