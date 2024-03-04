#include <stdio.h>
#define MAXN 100005
#define max(x,y) (x)>(y)?(x):(y)

int f[MAXN][17];

int log2(int x){
    int res=-1;
    while (x){
        x>>=1;
        res++;
    }
    return res;
}

int query(int l,int r){
    int k=log2(r-l+1); 
    return max(f[l][k],f[r-(1<<k)+1][k]);
}

int read()
{
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}

int main(){
    int m,n;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++){
        f[i][0]=read();
    }
    for(int j=1;j<=17;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
    int l,r;
    while (m--){
        l=read(),r=read();
        printf("%d\n",query(l,r));
    }
}