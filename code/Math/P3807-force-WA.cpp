#include <bits/stdc++.h>
using namespace std;
#define ll long long
int MOD;
const int maxfac=1e7;
/*
the original algorithm cannot compute C(select,base) if select+base>mod,
because the inverse element only exits if a and b is relatively prime.
*/

ll factorial[maxfac];

void getfac(){
    factorial[0]=1;
    for (int i=1;i<=MOD;i++){
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
    int T;
    //freopen("../../data/P3807_1.in","r",stdin);
    cin>>T;
    while (T--){
        ll m,n;
        cin>>n>>m>>MOD;
        getfac(n+m);
        cout<<C(n,n+m)<<endl;
    }
    return 0;
}