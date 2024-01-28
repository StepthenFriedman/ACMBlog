#include <stdio.h>
#define MAXN 500005
#define ll long long
#define lowbit(x) ((x)&(-x))
#define father(x) ((x)+lowbit(x))
#define left(x) ((x)-(lowbit(x)))

ll tree[MAXN]={0};
ll a[MAXN];

ll prefix_sum(ll x) {
  	ll ans=0;
  	while (x){
    	ans+=tree[x];
    	x-=lowbit(x);
  	}
  	return ans;
}

#define period_sum(x,y) (prefix_sum(y)-prefix_sum((x)-1))

void init(ll n){
	for (ll i=1;i<=n;i++){
		tree[i]+=a[i];
		ll j=father(i);
		if (j<=n) tree[j]+=tree[i];
	}
}

void add(ll n,ll i,ll k) {
	while (i<=n) {
		tree[i]+=k;
		i=father(i);
	}
}

ll read(){
	char c=getchar();
	ll f=1,x=0;
	while(c<'0'||c>'9'){
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+(c^'0');
		c=getchar();
	}
	return x*f;
}



int main(){
    ll m,n,i,ipt,x,y;
	freopen("../../data/P3374_1.in","r",stdin);
	n=read(),m=read();
	for (i=1;i<=n;i++) a[i]=read();
	init(n);
	while (m--){
		scanf("%lld%lld%lld",&ipt,&x,&y);
		if (ipt==1) add(n,x,y);
		else printf("%lld\n",period_sum(x,y));
	}
}