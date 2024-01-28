#include<cstdio>
#include<algorithm>
using namespace std;

const int mod=998244353;

int n,f[1000005],pw[1000005];
long long ans;

int main() {
	scanf("%d",&n);
	pw[0]=1;
	for (int i=1;i<=n;i++) pw[i]=2*pw[i-1]%mod;//pw[i]:2^i
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j+=i) f[j]++;//f[j]:the number of factors of j
	for (int i=1;i<=n;i++) ans=(ans+(long long)pw[max(n-i-1,0)]*f[i]%mod)%mod;//calculate answer
	printf("%lld\n",ans);
	return 0;
}