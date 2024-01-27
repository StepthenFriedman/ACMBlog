#include <stdio.h>

typedef struct xy{
    long long x,y;
}xy;

long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}

xy exgcd(long long a,long long b,long long c){
    if (a==1){
        xy res={c,0};
        return res;
    }
    if (b==1){
        xy res={0,c};
        return res;
    }
    if (a>1 && c>a && (!(c%a))){
        xy res={0,c/a};
        return res;
    }
    if (b>1 && c>b && (!(c%b))){
        xy res={0,c/b};
        return res;
    }
    if (c==a+b){
        xy res={1,1};
        return res;
    }
    if (a>b){
        xy res=exgcd(a-b,b,c);
        res.y-=res.x;
        return res;
    }
    if (b>a){
        xy res=exgcd(a,b-a,c);
        res.x-=res.y;
        return res;
    }
}

int main(){
    int T;
    scanf("%d",&T);
    while (T--){
        long long a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        int ABgcd=gcd(a,b);
        if (ABgcd!=1 && gcd(ABgcd,c)==1) {
            printf("-1\n");
            continue;
        }
        xy res=exgcd(a,b,c);
        printf("%lld %lld\n",res.x,res.y);
    }
}