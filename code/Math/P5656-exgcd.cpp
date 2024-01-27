#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

void exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){x=1;y=0;return ;}
    exgcd(b,a%b,x,y);
    ll z=x;x=y,y=z-y*(a/b);
}
/*
void exgcd(ll a,ll b,ll *x,ll* y){
    if (a==0){*x=0;*y=1;return;}
    exgcd(b%a,a,x,y);
    ll tmp=*y;
    *y=*x;
    *x=tmp-(b/a)*(*y);
}*/

int main(){
    int t;
    ll a,b,c,x,y;
    cin>>t;
    while (t--){
        cin>>a>>b>>c;
        ll ABgcd=gcd(a,b);
        ll ABCgcd=gcd(ABgcd,c);
        if (ABgcd!=1) {
            if (ABgcd!=ABCgcd){
                printf("-1\n");
                continue;
            }
            else{
                a/=ABCgcd,
                b/=ABCgcd,
                c/=ABCgcd;
            }
        }
        exgcd(a,b,x,y);
        if (x>y){
            //reverse x and y
            //suppose that always x<=0<y
            ll temp=x;x=y;y=temp;
            temp=a;a=b;b=temp;
            x*=c,y*=c;
            ABgcd=gcd(a,b);
            ll ai=a/ABgcd,bi=b/ABgcd;
            ll nmin,nmax;
            if (x==0) nmin=1;
            else nmin=((-x)/bi)+1;
            nmax=(y/ai)-!(y%ai);
            if (y<=nmin*ai){
                //no positive solution
                printf("%lld %lld\n",y-nmax*ai,x+nmin*bi);
            }else{
                printf("%lld %lld %lld %lld %lld\n",
                    nmax-nmin+1,
                    y-nmax*ai,x+nmin*bi,
                    y-nmin*ai,x+nmax*bi
                );
            }
        }else{
            x*=c,y*=c;
            ABgcd=gcd(a,b);
            ll ai=a/ABgcd,bi=b/ABgcd;
            ll nmin,nmax;
            if (x==0) nmin=1;
            else nmin=((-x)/bi)+1;
            nmax=(y/ai)-!(y%ai);
            //printf("n: %lld %lld ABgcd:%lld x:%lld y:%lld ai:%lld bi:%lld\n",nmin,nmax,ABgcd,x,y,ai,bi);
            if (y<=nmin*ai){
                //no positive solution
                printf("%lld %lld\n",x+nmin*bi,y-nmax*ai);
            }else{
                printf("%lld %lld %lld %lld %lld\n",
                    nmax-nmin+1,
                    x+nmin*bi,y-nmax*ai,
                    x+nmax*bi,y-nmin*ai
                );
            }
        }
    }
    return 0;
}