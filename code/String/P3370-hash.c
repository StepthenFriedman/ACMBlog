#include<stdio.h>
#include<string.h>

char ipt[1600];

typedef struct hashvalue{
    int hash,head,toe,len;
}hv;

hv total[10000];

hv hash(char* x){
    int len=strlen(x);
    int h=x[((len-1)/5)]+7*x[((len-1)/5)*2]+49*x[((len-1)/5)*3]+343*x[((len-1)/5)*4]+7*343*x[((len-1)/5)*4];
    hv hash={h,x[0],x[len-1],len};
    return hash;
}

int same(hv a,hv b){
    return (a.hash==b.hash)&&(a.head==b.head)&&(a.len==b.len)&&(a.toe==b.toe);
}

int main(){
    int n,j,k=0;
    scanf("%d",&n);
    while (n--){
        scanf("%s",ipt);
        hv value=hash(ipt);
        for (j=0;j<k;j++){
            if (same(total[j],value)){
                goto next;
            }
        }
        total[k++]=value;
        next:;
    }
    printf("%d\n",k);
    return 0;
}