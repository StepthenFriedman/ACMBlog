#include<stdio.h>
#include<string.h>
#define MAXN 205
#define ll long long
#define min(x,y) (x)<(y)?(x):(y)
#define max(x,y) ((x)>(y)?(x):(y))
#define ckmax(x,y) ((x)>(y)?0:(x=y))

ll arr[MAXN];

ll f[MAXN][MAXN]={0};

int n;

ll dfs(int l,int r){
    if (f[l][r]) return f[l][r];
    if (r-l<=1) return f[l][r]=0;
    if (r-l==2) return f[l][r]=arr[l]*arr[l+1]*arr[l+2];
    ll maxE=0;
    for (int i=l+1;i<r;i++){
        ckmax(maxE,dfs(l,i)+dfs(i,r)+arr[l]*arr[i]*arr[r]);
    }
    return f[l][r]=maxE;
}

int main(){
    freopen("../../data/P1063_1.in","r",stdin);
    int i,j;
    scanf("%d",&n);
    for (i=1;i<=n;i++) scanf("%lld",arr+i),arr[n+i]=arr[i];
    ll maxE=0;
    for (i=1;i<=n;i++){
        ll res=dfs(i,i+n-1)+arr[i]*arr[i]*arr[i+n-1];
        ckmax(maxE,res);
    }
    printf("%lld\n",maxE);
}