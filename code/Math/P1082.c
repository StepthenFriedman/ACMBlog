#include <stdio.h>

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

int main(){
    long long a,b,x;
    scanf("%lld%lld",&a,&b);
    xy res=exgcd(a,b);
    printf("%lld\n",res.x);
}