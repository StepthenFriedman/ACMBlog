#include<stdio.h>
#include<limits.h>
#define MAXN 101
#define MAXM 11
#define MAXSTATE 0b1001001001
#define ALLSTATE 73
#define ll long long
#define min(x,y) (x)<(y)?(x):(y)
#define max(x,y) ((x)>(y)?(x):(y))
#define ckmax(x,y) ((x)>(y)?0:(x=y))
#define ckmin(x,y) ((x)<(y)?0:(x=y))

int aviliable_state[ALLSTATE]={0,1,2,4,8,9,16,17,18,32,33,34,36,64,65,66,68,72,73,128,129,130,132,136,137,144,145,146,256,257,258,260,264,265,272,273,274,288,289,290,292,377,441,473,489,497,498,512,513,514,516,520,521,528,529,530,543,544,545,546,548,559,567,571,573,574,575,576,577,578,580,584,585};
int m,n;

int f[MAXN][75][75]={0};

int get_num(int x){
    int num=0;
    while (x){
        if (x%2) num++;
        x>>=1;
    }
    return num;
}

char map[MAXN]={0};

#define check_state_1(x,i) (((x)|map[i])==map[i])
#define check_state_2(x,ls) (!((x)&aviliable_state[ls]))

int main(){
    //freopen("../../data/P2704_1.in","r",stdin);
    //freopen("../../data/P2704.out","w",stdout);
    int i,j;
    scanf("%d%d",&n,&m);
    getchar();getchar();
    for (i=1;i<=n;i++){
        for (j=1;j<=m;j++){
            if (getchar()=='P') map[i]<<=1,map[i]+=1;
            else map[i]<<=1;
        }
        getchar();getchar();
    }
    i=1;
    //printf("i:%d\n",i);
    for (int s=0;s<73;s++){
        int state=aviliable_state[s];
        if (!check_state_1(state,i)){
            f[i][0][s]=-1;
            continue;
        }
        f[i][0][s]=get_num(state);
        //printf("  s:%04b res:%d\n",state,f[i][0][s]);
    }
    i=2;
    //printf("i:%d\n",i);
    for (int ls2=0;ls2<73;ls2++){
        if (f[1][0][ls2]==-1) continue;
        //printf("ls2:%04b\n",aviliable_state[ls2]);
        for (int s=0;s<73;s++){
            int state=aviliable_state[s];
            if (!check_state_1(state,i)){
                f[i][ls2][s]=-1;
                continue;
            }
            if (!check_state_2(state,ls2)){
                //printf("  s:%04b fail at check state 2\n",state);
                f[i][ls2][s]=-1;
                continue;
            }
            f[i][ls2][s]=f[1][0][ls2]+get_num(state);
            //printf("  s:%04b res:%d\n",state,f[i][ls2][s]);
        }
    }
    i=3;
    int max_state=(1<<m)-1;
    for (i=3;i<=n;i++){
        //printf("i:%d\n",i);
        for (int ls1=0;ls1<73 && aviliable_state[ls1]<=max_state;ls1++){
            //printf("ls1:%04b\n",aviliable_state[ls1]);
            for (int ls2=0;ls2<73 && aviliable_state[ls2]<=max_state;ls2++){
                //printf("ls2:%04b\n",aviliable_state[ls2]);
                if (f[i-1][ls1][ls2]==-1) continue;

                for (int s=0;s<73;s++){
                    int state=aviliable_state[s];
                    if (!check_state_1(state,i)){
                        //printf("  s:%04b fail at check state 1\n",state);
                        f[i][ls2][s]=-1;
                        continue;
                    }
                    if (!check_state_2(state,ls1) || !check_state_2(state,ls2)){
                        //printf("  s:%04b fail at check state 2\n",state);
                        f[i][ls2][s]=-1;
                        continue;
                    }
                    f[i][ls2][s]=f[i-1][ls1][ls2]+get_num(state);
                    //printf("  s:%04b\n    %04b\n    %04b\n res:%d\n",aviliable_state[ls1],aviliable_state[ls2],state,f[i][ls2][s]);
                }
            }
        }
    }
    int max_num=0;
    for (int ls1=0;ls1<73;ls1++)
        for (int ls2=0;ls2<73;ls2++)
            ckmax(max_num,f[n][ls1][ls2]);
    printf("%d\n",max_num);
    return 0;
}