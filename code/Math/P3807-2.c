#include<stdio.h>
#define ll long long
ll p;

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
ll n,m;
int T;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld%lld",&n,&m,&p);
		printf("%lld\n",(Lucas(n+m,m))%p);
	}
}