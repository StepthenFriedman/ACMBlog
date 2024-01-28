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

int main(){
    int n,i,j,k;ll temp;
    freopen("../../data/P4783_11.in","r",stdin);
    cin>>n;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            cin>>arr[i][j];
            arr[i][j+n]=(i==j);
        }
    }
    for (i=0;i<n-1;i++){
        if (!arr[i][i]){
            for (j=i+1;j<n;j++){
                if (arr[j][i]){
                    for (k=0;k<n*2;k++){
                        temp=arr[j][k];
                        arr[j][k]=arr[i][k];
                        arr[i][k]=temp;
                    }
                    break;
                }
            }
        }
        if(!arr[i][i]){
            puts("No Solution");return 0;
        }
        for (j=i+1;j<n;j++){
            for (k=i+1;k<2*n;k++){
                //each element
                arr[j][k]=(arr[j][k]*arr[i][i])%MOD;
                arr[j][k]=(arr[j][k]-arr[i][k]*arr[j][i])%MOD;
                while (arr[j][k]<0) arr[j][k]+=MOD;
            }
            arr[j][i]=0;
        }
    }
    if (arr[n-1][n-1]==0){
        cout<<"No Solution\n";
        return 0;
    }
    for (i=n-1;i>0;i--){
        for (j=i-1;j>=0;j--){
            for (k=i-1;k>=j;k--){
                //each element
                arr[j][k]=(arr[j][k]*arr[i][i])%MOD;
                arr[j][k]=(arr[j][k]-arr[i][k]*arr[j][i])%MOD;
                while (arr[j][k]<0) arr[j][k]+=MOD;
            }
            for (k=i+1;k<2*n;k++){
                //each element
                arr[j][k]=(arr[j][k]*arr[i][i])%MOD;
                arr[j][k]=(arr[j][k]-arr[i][k]*arr[j][i])%MOD;
                while (arr[j][k]<0) arr[j][k]+=MOD;
            }
            arr[j][i]=0;
        }
    }
    for (i=0;i<n;i++){
        ll rate=inv(arr[i][i]);
        for (j=n;j<2*n;j++){
            arr[i][j]=(arr[i][j]*rate)%MOD;
            while (arr[i][j]<0) arr[i][j]+=MOD;
        }
        arr[i][i]=arr[i][i]*inv(arr[i][i])%MOD;
    }
    for (i=0;i<n;i++){
        for (j=n;j<2*n;j++){
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}