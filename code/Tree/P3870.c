#include <stdio.h>
#define ll long long

ll open[100005]={0};

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
    ll m,n,a,b;
	freopen("../../data/P3870.in","r",stdin);
	n=read(),m=read();
	while (m--){
		if (read()==0){
            scanf("%lld%lld",&a,&b);
			ll now_open=open[b]-open[a-1];
			ll to_close=b-a+1-now_open;
        }
		else{
            scanf("%lld%lld",&a,&b);
        }
	}
}