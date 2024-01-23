#include<stdio.h>
#include<stdlib.h>
#define MOD 1000000007

long long *x,*tmp;
int n;

void cpy(long long *dst,long long *src){
    int i,j;
    for (i=0;i<n;i++) for (j=0;j<n;j++) dst[i*n+j]=src[i*n+j]%MOD;
}

void mul(long long *dst,long long *src){
    int i,j,k;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            tmp[i*n+j]=0;
            for (k=0;k<n;k++){
                tmp[i*n+j]=(tmp[i*n+j]+((dst[k*n+j]*src[i*n+k])%MOD))%MOD;
            }
            tmp[i*n+j]%=MOD;
        }
    }
    cpy(dst,tmp);
}

void power(long long k){
    if (k<2) return;
    else if (k%2) {
        long long *y=(long long*)malloc(n*n*sizeof(long long));
        cpy(y,x);
        power(k-1);
        mul(x,y);
        free(y);
    }
    else {
        mul(x,x);power(k/2);
    }
}

int main(){
    int i,j;
    long long k;
    scanf("%d%lld",&n,&k);
    x=(long long*)malloc(n*n*sizeof(long long));
    tmp=(long long*)malloc(n*n*sizeof(long long));
    for (i=0;i<n;i++) for (j=0;j<n;j++){
        scanf("%lld",&x[i*n+j]);
    }
    if (k==0){
        for (i=0;i<n;i++) for (j=0;j<n;j++){
            x[i*n+j]=(i==j);
        }
        goto end;
    }
    power(k);
    end:
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            printf("%lld ",x[i*n+j]);
        }
        putchar('\n');
    }
    free(x);
    free(tmp);
    return 0;
}