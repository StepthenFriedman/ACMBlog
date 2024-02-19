#include<stdio.h>
#include<string.h>
#define MAXN 60522
#define MAXJ 5000
#define ll long long
#define MOD 1000000007
#define min(x,y) (x)<(y)?(x):(y)
#define max(x,y) ((x)>(y)?(x):(y))
#define ckmax(x,y) ((x)>(y)?0:(x=y))

int arr[MAXN];
int f[MAXN][MAXJ]={0};
int n;

ll dfs(int start,int j){
    if (arr[start]%j) return 0;
    if (j<MAXJ && f[start][j]){
        printf("speed up!\n");
        return f[start][j];
    }
    ll sum=1;
    for (int ptr=start+1;ptr<=n;ptr++){
        if (!(arr[ptr]%(j+1))){
            sum+=dfs(ptr,j+1);
        }
    }
    sum%=MOD;
    if (j<MAXJ) f[start][j]=sum;
    return sum;
}

int main(){
    ll sum=0;
    freopen("../../data/CF1061C.in","r",stdin);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",arr+i);
    for (int i=1;i<=n;i++) {
        sum+=dfs(i,1);
        sum%=MOD;
    }
    printf("%lld\n",sum);
}