#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
const long long MOD=1e9+7;

long long x[105][105]={0},
tmp[105][105]={0};
int n;

inline long long read(){
	char c=getchar();
	long long f=1,x=0;
	while(c<'0'||c>'9'){
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+(c^'0');
		c=getchar();
	}
	return x*f;
}

void cpy(long long dst[105][105],long long src[105][105]){
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) dst[i][j]=src[i][j]%MOD;
}

void mul(long long dst[105][105],long long src[105][105]){
    int i,j,k;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            tmp[i][j]=0;
            for (k=0;k<n;k++){
                tmp[i][j]=(tmp[i][j]+((dst[k][j]*src[i][k])%MOD))%MOD;
            }
            tmp[i][j]%=MOD;
        }
    }
    cpy(dst,tmp);
}

void power(long long k){
    if (k<2) return;
    else if (k%2) {
        long long y[105][105];
        cpy(y,x);
        power(k-1);
        mul(x,y);
    }
    else {
        mul(x,x);power(k/2);
    }
}

int main(){
    long long k;
    int i,j;
    scanf("%d%lld",&n,&k);
    for (i=0;i<n;i++) for (j=0;j<n;j++){
        x[i][j]=read();
    }
    if (k==0){
        for (i=0;i<n;i++) for (j=0;j<n;j++){
            x[i][j]=(i==j);
        }
        goto end;
    }
    power(k);
    end:
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            printf("%lld ",x[i][j]);
        }
        putchar('\n');
    }
    return 0;
}