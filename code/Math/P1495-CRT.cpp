#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll ai[15],ni[15];

void exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){x=1;y=0;return ;}
    exgcd(b,a%b,x,y);
    int z=x;x=y,y=z-y*(a/b);
}

ll inv(ll a,ll b){
    ll x,y;
    exgcd(a,b,x,y);
    return (x+b)%b;
}

int main(){
    int i,n;
    scanf("%d",&n);
    ll nmul=1,ans=0;
    for (i=0;i<n;i++){
        scanf("%lld%lld",ni+i,ai+i);
        nmul*=ni[i];
    }
    for (i=0;i<n;i++){
        ll mi=nmul/ni[i];
        ll mrev=inv(mi,ni[i]);
        ans=(ans+mi*mrev*ai[i])%nmul;
    }
    printf("%lld\n",ans);
}