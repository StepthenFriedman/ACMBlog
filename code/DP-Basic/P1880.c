#include<stdio.h>
#include<limits.h>
#define min(x,y) (x)<(y)?(x):(y)
#define max(x,y) (x)>(y)?(x):(y)

typedef struct tuple{
    int m,n;
}tuple;

tuple a,b;

int getmax(int*arr,int*sum,int start,int end){
    if (start>=end-1) {
        return 0;
    }
    else if (start+2==end) {
        return arr[start]+arr[start+1];
    }
    int s=sum[end]-sum[start],
    maxval=0;

    for (int ptr=start+1;ptr<end;ptr++){
        maxval=max(maxval,getmax(arr,sum,start,ptr)+getmax(arr,sum,ptr,end));
    }
    return maxval+s;
}

int getmin(int*arr,int*sum,int start,int end){
    if (start>=end-1) {
        return 0;
    }
    else if (start+2==end) {
        return arr[start]+arr[start+1];
    }
    int s=sum[end]-sum[start],
    minval=INT_MAX;

    for (int ptr=start+1;ptr<end;ptr++){
        minval=min(minval,getmin(arr,sum,start,ptr)+getmin(arr,sum,ptr,end));
    }
    return minval+s;
}
/*
tuple get(int*arr,int*sum,int start,int end){
    if (start>=end-1){
        tuple t={0,0};
        return t;
    }
    else if (start+2==end) {
        tuple t={arr[start]+arr[start+1],arr[start]+arr[start+1]};
        return t;
    }
    int s=sum[end]-sum[start],
    maxval=0,minval=INT_MAX;
    for (int ptr=start+1;ptr<end;ptr++){
        a=get(arr,sum,start,ptr);
        b=get(arr,sum,ptr,end);
        maxval=max(maxval,a.m+b.m);
        minval=min(minval,a.n+b.n);
    }
    tuple t={maxval+s,minval+s};
    return t;
}*/

tuple getCircle(int*arr,int*sum,int start,int n){
    int maxval=0,minval=INT_MAX;
    for (int i=0;i<n-1;i++){
        maxval=max(maxval,getmax(arr,sum,start+i,n+i));
        minval=min(minval,getmin(arr,sum,start+i,n+i));
    }
    tuple t={maxval,minval};
    return t;
}

int main(){
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
    //tuple t=getCircle(stone,sum,0,n);
    //printf("%d\n%d\n",t.n,t.m);
    get(stone,sum,0,1);
    return 0;  
} 