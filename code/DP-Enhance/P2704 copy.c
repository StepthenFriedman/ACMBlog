#include<stdio.h>
#include<limits.h>
#define MAXN 101
#define MAXM 11
#define MAXSTATE 0b1001001001
#define ll long long
#define min(x,y) (x)<(y)?(x):(y)
#define max(x,y) ((x)>(y)?(x):(y))
#define ckmax(x,y) ((x)>(y)?0:(x=y))
#define ckmin(x,y) ((x)<(y)?0:(x=y))

int aviliable_state[]={0,1,2,4,8,9,16,17,18,32,33,34,36,64,65,66,68,72,73,128,129,130,132,136,137,144,145,146,256,257,258,260,264,265,272,273,274,288,289,290,292,377,441,473,489,497,498,512,513,514,516,520,521,528,529,530,543,544,545,546,548,559,567,571,573,574,575,576,577,578,580,584,585};
int m,n;
int vec[5],num;

int f[MAXN][75][75];

void get_state(int x){
    int i=0;num=0;
    next:
    if (x%2) vec[num++]=m-i;
    if (x) {
        x>>=1;
        i++;
        goto next;
    }
}

int check_state(){
    if (num>4) return 0;
    if (!num) return 1;
    for (int i=1;i<num;i++) if (vec[i-1]-vec[i]<3) return 0;
    return 1;
}

char map[MAXN][MAXM];

int main(){
    freopen("../../data/P2704.in","r",stdin);
    int i,j;
    scanf("%d%d",&n,&m);
    getchar();
    for (i=1;i<=n;i++){
        for (j=1;j<=m;j++){
            map[i][j]=getchar();
        }
        getchar();
    }
    //for (i=1;i<)
    return 0;
}