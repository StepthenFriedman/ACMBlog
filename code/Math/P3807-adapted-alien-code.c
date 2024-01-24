#include<stdio.h>
#define ll long long
ll p;

typedef struct xy{
    ll x,y;
}xy;

xy exgcd(ll a,ll b){
    if (a==1){
        xy res={1,0};
        return res;
    }
    if (a==b+1){
        xy res={1,1};
        return res;
    }
    if (a>b){
        if (a>2*b && b>1){
            ll t=a/b;
            xy res=exgcd(a-t*b,b);
            res.y+=res.x*t;
            return res;
        }else{
            xy res=exgcd(a-b,b);
            res.y+=res.x;
            return res;
        }
    }
    if (b>a){
        if (b>2*a && a>1){
            ll t=b/a;
            xy res=exgcd(a,b-t*a);
            res.x+=res.y*t;
            return res;
        }else{     
            xy res=exgcd(a,b-a);
            res.x+=res.y;
            return res;
        }
    }
}

ll C(ll n,ll m){
	if(n<m) return 0;
	if(m>n-m) m=n-m;
	ll a=1,b=1;
	for(int i=0;i<m;i++){
		a=(a*(n-i))%p;
		b=(b*(i+1))%p;
	}
    ll revb=exgcd(b,p).x;
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