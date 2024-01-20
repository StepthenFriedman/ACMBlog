#include<stdio.h>
#include<string.h>
#include<limits.h>
#define min(x,y) (x)<(y)?(x):(y)
#define max(x,y) (x)>(y)?(x):(y)



typedef struct tuple{
    int m,n;
}tuple;

tuple f[205][205];

tuple get(int*arr,int*sum,int start,int end){
    if (f[start][end].m){
        return f[start][end];
    }
    if (start>=end-1){
        tuple t={0,0};
        f[start][end]=t;
        return t;
    }
    else if (start+2==end) {
        tuple t={arr[start]+arr[start+1],arr[start]+arr[start+1]};
        return t;
    }
    int s=sum[end]-sum[start],
    maxval=0,minval=INT_MAX;
    for (int ptr=start+1;ptr<end;ptr++){
        tuple a=get(arr,sum,start,ptr);
        tuple b=get(arr,sum,ptr,end);
        maxval=max(maxval,a.m+b.m);
        minval=min(minval,a.n+b.n);
    }
    tuple t={maxval+s,minval+s};
    f[start][end]=t;
    return t;
}

tuple getCircle(int*arr,int*sum,int start,int n){
    int maxval=0,minval=INT_MAX;
    tuple recv;
    for (int i=0;i<n-1;i++){
        //memset
        recv=get(arr,sum,start+i,n+i);
        maxval=max(maxval,recv.m);
        minval=min(minval,recv.n);
    }
    tuple t={maxval,minval};
    return t;
}

int main(){
    memset(f,0,sizeof(tuple)*205*205);
    int i,j,n;
    scanf("%d",&n);
    int stone[n*2],sum[(n+1)*2];
    sum[0]=0;
    for (i=0;i<n;i++) {
        scanf("%d",stone+i);
        sum[i+1]=sum[i]+stone[i];
    }
    for (i=n;i<2*n-1;i++) {
        stone[i]=stone[i-n];
        sum[i+1]=sum[i]+stone[i];
    } 
    tuple t=getCircle(stone,sum,0,n);
    printf("%d\n%d\n",t.n,t.m);
    return 0;  
}