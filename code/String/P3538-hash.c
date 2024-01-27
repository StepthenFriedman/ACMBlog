#include <stdio.h>
#define int long long
#define MOD 1000000007
#define PRIME 100000000
#define N 500005

signed a[PRIME]={0};

int hash[N],power[N],g[N];
int n;

char s[N+1];

//get the minimal prime factor of each number
void initprime(){
    a[1]=1;
    int i=2,j,pass;
    next:
    pass=0;
    for (j=i+i;j<=n;j+=i) if (!a[j]) {
        a[j]=i;pass=1;
    }
    i++;
    while (a[i]) i++;
    if (pass) goto next;
    for (i=0;i<=n;i++) if (!a[i]) a[i]=i;
}

void initpower(){
    power[0]=1;
	for (int i=1;i<=n;i++)
		power[i]=(power[i-1]*29)%MOD;
}

void inithash(){
    hash[0]=s[0]-'a';
    for (int i=1;i<=n;i++)
		hash[i]=(hash[i-1]*29+s[i]-'a')%MOD;
}

int gethash(int l,int r) {
	return ((hash[r]-hash[l-1]*power[r-l+1])%MOD+MOD)%MOD;
}

signed main(){
    int q;
    scanf("%lld%s%lld",&n,s,&q);
    initpower();
    inithash();
    initprime();
    while (q--){
		int l,r,len,ans;
		scanf("%lld%lld",&l,&r);
        l--;r--;
        ans=len=r-l+1;
        if (gethash(l+1,r)==gethash(l,r-1)) {
            puts("1");
            continue;
        }
		while (len>1) {
			if (gethash(l+ans/a[len],r)==gethash(l,r-ans/a[len]))
				ans/=a[len];
			len/=a[len];
		}
		printf("%lld\n", ans);
	}
    return 0;
}