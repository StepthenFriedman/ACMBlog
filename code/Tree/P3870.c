#include <stdio.h>
#define MAXN 500005
#define ll long long
#define lowbit(x) ((x)&(-x))
#define father(x) ((x)+lowbit(x))
#define left(x) ((x)-(lowbit(x)))

ll tree[MAXN]={0};
ll n;

void add(ll i,ll num){
	//from i to n
	for(;i<=n;i=father(i)) tree[i]+=num;//差分
}
void opera(ll n,ll l,ll r){
	ll num=r-l+1-ask();
	add(l,num),add((r)+1,-(num));
}

ll ask(ll i){
	ll ans=0;
	for(;i>=1;i=left(i)) ans+=tree[i];
	return ans;
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
    ll m,ipt,a,b;
	freopen("../../data/P3870.in","r",stdin);
	n=read(),m=read();
	while (m--){
        ipt=read();
		if (ipt==0){
            scanf("%lld%lld",&a,&b);
            change_period(x,y);
        }
		else{
            scanf("%lld%lld",&a,&b);
            printf("%lld\n",ask_period(x));
        }
	}
}