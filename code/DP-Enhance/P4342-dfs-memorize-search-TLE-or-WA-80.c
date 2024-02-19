#include<stdio.h>
#include<limits.h>
#define MAXN 205
#define ll long long
#define min(x,y) (x)<(y)?(x):(y)
#define max(x,y) ((x)>(y)?(x):(y))
#define ckmax(x,y) ((x)>(y)?0:(x=y))
#define add 0
#define plus 1

ll arr[MAXN];
char operation[MAXN];

ll res[MAXN];
ll f[MAXN][MAXN]={0};
int n;

char ipt[3];

ll dfs(int l,int r){
    if (l>n && r>n && f[l-n][r-n]) return f[l][r]=f[l-n][r-n];
    if (f[l][r]) return f[l][r];
    if (r<l) return 0;
    if (r==l) return arr[l];
    if (r-l==1) {
        if (operation[r]==add) return f[l][r]=arr[l]+arr[r];
        else return f[l][r]=arr[l]*arr[r];
    }
    ll maxE=LONG_MIN;
    for (int i=l+1;i<=r;i++){
        if (operation[i]==add) ckmax(maxE,dfs(l,i-1)+dfs(i,r));
        else ckmax(maxE,dfs(l,i-1)*dfs(i,r));
    }
    return f[l][r]=maxE;
}

int main(){
    freopen("../../data/P4342.in","r",stdin);
    int i,j;
    scanf("%d",&n);
    for (i=1;i<=n;i++){
        scanf("%s%lld",ipt,arr+i);
        if (ipt[0]=='t') operation[i]=add;
        else operation[i]=plus;
        operation[n+i]=operation[i];
        arr[n+i]=arr[i];
    }
    ll maxE=LONG_MIN;
    for (i=1;i<=n;i++){
        res[i]=dfs(i,i+n-1);
        ckmax(maxE,res[i]);
    }
    printf("%lld\n",maxE);
    for (i=1;i<=n;i++) if (res[i]==maxE) printf("%d ",i);
    putchar('\n');
}