#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
ll arr[400][800];

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

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

ll lcm(ll a,ll b){
    ll g=gcd(a,b);
    return a*(b/g);
}

int main(){
    int n,i,j,k;
    cin>>n;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            cin>>arr[i][j];
            arr[i][j+n]=(i==j);
        }
    }
    for (i=0;i<n-1;i++){
        for (j=i+1;j<n;j++){
            ll IJgcd=gcd(arr[i][i],arr[j][i]);
            ll ir=arr[j][i]/IJgcd,jr=arr[i][i]/IJgcd;
            for (k=i+1;k<2*n;k++){
                //each element
                arr[j][k]*=jr;
                arr[j][k]-=arr[i][k]*ir;
                arr[j][k]=(arr[j][k]+MOD)%MOD;
            }
            arr[j][i]=0;
            if (arr[j][i+1]==0){
                cout<<"No Solution\n";
                return 0;
            }
        }
    }
    for (i=n-1;i>0;i--){
        for (j=i-1;j>=0;j--){
            ll IJgcd=gcd(arr[i][i],arr[j][i]);
            ll ir=arr[j][i]/IJgcd,jr=arr[i][i]/IJgcd;
            for (k=i-1;k>=j;k--){
                //each element
                arr[j][k]*=jr;
                arr[j][k]-=arr[i][k]*ir;
                arr[j][k]=(arr[j][k]+MOD)%MOD;
            }
            for (k=i+1;k<2*n;k++){
                //each element
                arr[j][k]*=jr;
                arr[j][k]-=arr[i][k]*ir;
                arr[j][k]=(arr[j][k]+MOD)%MOD;
            }
            arr[j][i]=0;
        }
    }
    ll l=1;
    for (i=0;i<n;i++){
        l=lcm(l,abs(arr[i][i]));
    }
    for (i=0;i<n;i++){
        ll rate=l/arr[i][i];
        for (j=n;j<2*n;j++){
            arr[i][j]=(arr[i][j]*rate)%MOD;
            arr[i][j]=arr[i][j]*inv(l)%MOD;
            while (arr[i][j]<0) arr[i][j]+=MOD;
        }
    }

    for (i=0;i<n;i++){
        for (j=n;j<2*n;j++){
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}