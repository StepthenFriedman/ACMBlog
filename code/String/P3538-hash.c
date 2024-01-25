#include <stdio.h>
#define int long long
#define MOD 1000000007
#define PRIME 100000000
#define N 500005

signed a[PRIME]={0};
signed prime[PRIME/100];

int hash[N],power[N],g[N];
int n;

char s[N+1];

void Euler(int n){
    int i=2,j,pass;
    a[0]=a[1]=1;

    next:
    pass=0;
    for (j=i+i;j<=n;j+=i) if (!a[j]) {
        a[j]=1;pass=1;
    }
    i++;
    while (a[i]) i++;
    if (pass) goto next;
    i=j=0;
    while (1){
        i++;
        while (a[i]) i++;
        if (i>=n) return;
        prime[j++]=i;
    }
}

void initpower(){
    power[0]=1;
	for (int i=1;i<=n;i++)
		power[i]=(power[i-1]*29)%MOD;
}

void inithash(){
    hash[0]=0;
    for (int i=1;i<=n;i++)
		hash[i]=(hash[i-1]*29+s[i]-'a'+1)%MOD;
}

int gethash(int l,int r) {
	return ((hash[r]-hash[l-1]*power[r-l+1])%MOD+MOD)%MOD;
}

signed main(){
    int q;
    scanf("%lld%s%lld",&n,s,&q);
    initpower();
    inithash();
    while (q--){
		int l,r,len,ans;
		scanf("%lld%lld",&l,&r);
        ans=len=r-l+1;
		if (calc(l+1, r)==calc(l, r-1)) {
			puts("1");
			continue;
		}
		while (len > 1) {
			if (calc(l+ans/g[len],r)==calc(l,r-ans/g[len]))
				ans /= g[len];// 除掉循环次数的因子
			len /= g[len];//分解
		}
		printf("%d\n", ans);
	}
    return 0;
}