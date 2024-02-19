#include <stdio.h>
#define ll long long
#define MAXN 50005

typedef struct prefix_max_segment_sum{
    int l,r;ll sum;
}pmps;


int arr[MAXN];
ll prefix_sum[MAXN];
pmps prefix_mps[MAXN];

#define priod_sum(l,r) (perfix_sum(r)-perfix_sum((l)-1))

int read(){
    char s;
    int k=0,base=1;
    while((s=getchar())!='-'&&s!=EOF&&!(s>='0'&&s<='9'));
    if(s==EOF)exit(0);
    if(s=='-')base=-1,s=getchar();
    while(s>='0'&&s<='9')
    {
        k=k*10+(s-'0');
        s=getchar();
    }
    return k*base;
}

int main(){
    int m,n=read(),i,l=1,r=1,ipt;
    perfix_sum[0]=0;
    int rightmost=0;
    for (i=1;i<=n;i++){
        arr[i]=read();
        perfix_sum[i]=ipt+perfix_sum[i-1];
        if (ipt<0)
    }
    m=read();
    while (m--){
        l=read();r=read();
        //while (arr[r]<0) r--;
        //while (arr[l]<0) l++;
        if (prefix_mps[r].l>arr[l]){
            printf("%lld\n",prefix_mps[r].sum);
            continue;
        }
        else{
            ll left_sum=0;
            for (int k=l;k<=r;k++){
                if (k<0){
                    
                }
            }
        }
    }
}