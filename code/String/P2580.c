#include <stdio.h>
#include <string.h>
#define EX 6

char ipt[1600];

typedef struct hashvalue{
    long long hash;
    int head,toe,len;
}hv;

hv total[10000];

hv named[10000];

hv hash(char* x){
    int len=strlen(x);
    long long h=x[((len-1)/EX)]+7*x[((len-1)/EX)*2]+49*x[((len-1)/EX)*3]+343*x[((len-1)/EX)*4]+7*343*x[((len-1)/EX)*4]+49*343*x[((len-1)/EX)*5];;
    hv hash={h,x[0],x[len-1],len};
    return hash;
}

int same(hv a,hv b){
    return (a.hash==b.hash)&&(a.head==b.head)&&(a.len==b.len)&&(a.toe==b.toe);
}

int main(){
    int n,m,i,j,nd=0;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%s",ipt);
        total[i]=hash(ipt);
    }
    scanf("%d",&m);
    for (i=0;i<m;i++){
        scanf("%s",ipt);
        hv newh=hash(ipt);
        for (j=0;j<nd;j++){
            if (same(newh,named[j])){
                printf("REPEAT\n");
                goto next;
            }
        }
        for (j=0;j<n;j++){
            if (same(newh,total[j])){
                printf("OK\n");
                named[nd++]=newh;
                goto next;
            }
        }
        printf("WRONG\n");
        next:;
    }
}