#include <stdio.h>
#define min(x,y) (x)<(y)?(x):(y)
long long p;

typedef struct xy{
    long long x,y;
}xy;

xy exgcd(long long a,long long b){
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
            long long t=a/b;
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
            long long t=b/a;
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

long long C(long long select,long long base){
    select=min(select,base-select);
    long long a=1,b=1;
	for(int i=0;i<base;i++){
		a=(a*(i+1))%p;
		b=(b*(select-i))%p;
	}
    long long revb=exgcd(b,p).x;
    return (a*revb)%p;
}

long long Lucus(long long select,long long base){
    if (select>base){
        return 0;
    }
    if (base==1){
        return 1;
    }
    if (select==0){
        return 1;
    }
    if (select==1){
        return base%p;
    }
    if (select<p && base<p){
        return C(select,base);
    }
    return (Lucus(select/p,base/p)*C(select%p,base%p))%p;
}

int main(){
    int T;
    long long m,n,base,select;
    scanf("%d",&T);
    while (T--){
        scanf("%lld%lld%lld",&m,&n,&p);
        base=m+n;
        select=min(m,n);
        printf("%lld\n",Lucus(select,base));
    }
}