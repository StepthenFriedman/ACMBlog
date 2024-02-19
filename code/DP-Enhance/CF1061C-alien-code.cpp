#include<bits/stdc++.h>
#define ll  long long
using namespace std;
ll n,ans,mod=1e9+7;
ll a[1000010],f[1000010];//用于dp的f[i]表示目前为止长度为i的合法序列个数 
ll w[1000010];//存放a[i]的每一个因数 
int main(){
	cin>>n;
	for(ll i=1;i<=n;++i)cin>>a[i];
	f[0]=1;//为了使f能够合乎常理（？）地DP 
	for(ll i=1;i<=n;++i){
		ll qq=sqrt(a[i]),top=0;
		for(ll j=1;j<=qq;j++){
			if(a[i]%j==0){
				w[++top]=j;
				if(j*j!=a[i])//这句缺失会导致错误，如1,1,2->5就WA了 
					w[++top]=a[i]/j;
			}
		}
		for(ll j=top;j>=1;--j){
			f[w[j]]=(f[w[j]]+f[w[j]-1])%mod;
		}
	}
	for(ll i=1;i<=n;++i)ans=(ans+f[i])%mod;
	cout<<ans;
} 