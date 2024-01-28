#include <stdio.h>
#define MAXN 500005
#define ll long long
#define lowbit(x) ((x)&(-x))
#define father(x) ((x)+lowbit(x))
#define left(x) ((x)-(lowbit(x)))

ll tree[MAXN]={0};//tree 维护差分后的修改量
ll a[MAXN];//原始数组
ll n;

void add(ll i,ll num){
	//from i to n
	for(;i<=n;i=father(i)) tree[i]+=num;//差分
}

#define add_period(l,r,num) (add(l,num),add((r)+1,-(num)))

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

ll ask(ll i){
	ll ans=0;
	for(;i>=1;i=left(i)) ans+=tree[i];
	return ans;
}

int main(){
    ll m,i,ipt,x,y,k;
	//freopen("../../data/P3368.in","r",stdin);
	n=read(),m=read();
	for (i=1;i<=n;i++) a[i]=read();
	while (m--){
        ipt=read();
		if (ipt==1){
            scanf("%lld%lld%lld",&x,&y,&k);
            add_period(x,y,k);
        }
		else{
            scanf("%lld",&x);
            printf("%lld\n",a[x]+ask(x));
        }
	}
}