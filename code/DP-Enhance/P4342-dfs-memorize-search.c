#include<stdio.h>
#include<limits.h>
#define MAXN 105
#define ll long long
#define min(x,y) (x)<(y)?(x):(y)
#define max(x,y) ((x)>(y)?(x):(y))
#define ckmax(x,y) ((x)>(y)?0:(x=y))
#define ckmin(x,y) ((x)<(y)?0:(x=y))
#define add 0
#define plus 1

ll arr[MAXN];
char operation[MAXN];

ll res[MAXN];
ll f[MAXN][MAXN]={0}; //max results
ll g[MAXN][MAXN]={0}; //min results
/*why recording min results?

because nagative*nagative=positive
*/
int n;

char ipt[3];

ll dfs_min(int l,int r);

ll dfs(int l,int r){
    if (l>n && r>n && f[l-n][r-n]) return f[l][r]=f[l-n][r-n];
    if (f[l][r]) return f[l][r];
    if (r<l) return 0;
    if (r==l) return arr[l];
    if (r-l==1) {
        if (operation[r]==add) return f[l][r]=arr[l]+arr[r];
        else return f[l][r]=arr[l]*arr[r];
    }
    ll maxE=LLONG_MIN;
    for (int i=l+1;i<=r;i++){
        if (operation[i]==add) ckmax(maxE,dfs(l,i-1)+dfs(i,r));
        else{
            ll max1=dfs(l,i-1),max2=dfs(i,r),
               min1=dfs_min(l,i-1),min2=dfs_min(i,r);
            ckmax(maxE,max(max(max1*max2,min1*min2),max(max1*min2,min1*max2)));
        }
    }
    return f[l][r]=maxE;
}

ll dfs_min(int l,int r){
    if (l>n && r>n && g[l-n][r-n]) return g[l][r]=g[l-n][r-n];
    if (g[l][r]) return g[l][r];
    if (r<l) return 0;
    if (r==l) return arr[l];
    if (r-l==1) {
        if (operation[r]==add) return g[l][r]=arr[l]+arr[r];
        else return g[l][r]=arr[l]*arr[r];
    }
    ll minE=LLONG_MAX;
    for (int i=l+1;i<=r;i++){
        if (operation[i]==add) ckmin(minE,dfs_min(l,i-1)+dfs_min(i,r));
        else {
            ll max1=dfs(l,i-1),max2=dfs(i,r),
               min1=dfs_min(l,i-1),min2=dfs_min(i,r);
            ckmin(minE,min(min(max1*max2,min1*min2),min(max1*min2,min1*max2)));
        }
    }
    return g[l][r]=minE;
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
    ll maxE=LLONG_MIN;
    for (i=1;i<=n;i++){
        res[i]=dfs(i,i+n-1);
        ckmax(maxE,res[i]);
    }
    printf("%lld\n",maxE);
    for (i=1;i<=n;i++) if (res[i]==maxE) printf("%d ",i);
    putchar('\n');
}