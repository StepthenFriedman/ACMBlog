#include <stdio.h>
#define MAXN 300005
#define ll long long
#define min(x,y) (x)<(y)?(x):(y)
#define max(x,y) (x)>(y)?(x):(y)
#define lowbit(x) ((x)&(-x))
#define father(x) ((x)+lowbit(x))
#define left(x) ((x)-(lowbit(x)))
#define dbg(arr) printf(#arr": "); for (int iii=1;iii<=n;iii++) printf("%lld ",arr[iii]); putchar('\n');

/*
the situation where dulplicate message are sent wans't thought of.
*/

ll n;
ll position[MAXN]={0};
ll res[MAXN]={0};
ll tree[MAXN]={0};

void add(ll i,ll num){
	//from i to n
	for(;i<=n;i=father(i)) tree[i]+=num;//差分
}

#define add_period(l,r,num) (add((l),(num)),add((r)+1,-(num)))

ll ask(ll i){
	ll ans=0;
	for(;i>=1;i=left(i)) ans+=tree[i];
	return ans;
}

int main(){
    ll m,ipt,i,j;
	freopen("../../data/CF1288E.in","r",stdin);
	scanf("%lld%lld",&n,&m);
	j=m;
	for (i=0;i<m;i++){
		scanf("%lld",&ipt);
		res[ipt]=ask(ipt)+ipt;
		add_period(1,ipt,1);
		//dbg(tree);
		position[ipt]=j--;
	}
	//dbg(position);
	for (i=1;i<=n;i++){
		if (position[i]) printf("1 %lld\n",max(res[i],position[i]));
		else printf("%lld %lld\n",i,ask(i)+i);
	}
}