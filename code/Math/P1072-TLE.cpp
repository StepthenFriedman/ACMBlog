#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

ll n;

int main(){
    //freopen("../../data/P1072_7.in","r",stdin);
    ll a0,a1,b0,b1,b2;
    cin>>n;
    while (n--){
        cin>>a0>>a1>>b0>>b1;
        if (b1%a1!=0){
            cout<<"0\n";
        }else{
            /*
            this is an O(n) openation.
            compared to the AC code, which is O(n^0.5), although its step was a1, time complexity always comes first. 
            */
            ll x=0;
            int ans=0;
            for (x=a1;x<=b1;x+=a1){
                if (b1%x==0 && gcd(x/a1,a0/a1)==1 && gcd(b1/x,b1/b0)==1)
                    ans++;
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}