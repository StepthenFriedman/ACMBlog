#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD=1e9+9;
const int maxfac=1e7;
ll factorial[maxfac];

void getfac(int n){
    factorial[0]=1;
    for (int i=1;i<=n;i++){
        factorial[i]=(factorial[i-1]*i+MOD)%MOD;
    }
}

void exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){x=1;y=0;return ;}
    exgcd(b,a%b,x,y);
    ll z=x;x=y,y=z-y*(a/b);
}

ll inv(ll a){
    ll x,y;
    exgcd(a,MOD,x,y);
    return (x+MOD)%MOD;
}

ll C(ll select,ll base){
    return (((factorial[base]*inv(factorial[select]))%MOD)*inv(factorial[base-select]))%MOD;
}

int main(){
    getfac(1000);
    ll a,b;
    cin>>a>>b;
    cout<<C(a,b)<<endl;
    return 0;
}