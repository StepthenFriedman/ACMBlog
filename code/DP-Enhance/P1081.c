#include<stdio.h>
#include<string.h>
#include<limits.h>
#define MAXN 100005
#define ll long long
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define ckmax(x,y) ((x)>(y)?0:(x=y))
#define abssub(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))

int A[MAXN]={0};
int B[MAXN]={0};
int city[MAXN];

int main(){
    freopen("../../data/P1081.in","r",stdin);
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",city+i);
    for (int i=1;i<n;i++){
        int nearest1=LONG_MAX,nearest2=LONG_MAX;
        int i1=0,i2=0;
        for (int j=i+1;j<n;j++){
            if (abssub(city[i],city[j])>nearest1){
                
            }
        }
    }
}