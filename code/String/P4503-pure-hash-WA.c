#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define EXACT 7

typedef struct hashvalue{
    long long *s;
}hv;

hv totalhv[30000];
char ipt[201];

char cast(char x){
    if (x>='a'&&x<='z') return x-'a';
    if (x>='A'&&x<='Z') return x-'A'+26;
    if (x>='0'&&x<='9') return x-'0'+52;
    if (x=='_') return 62;
    if (x=='@') return 63;
}

hv hash(char* x,int len){
    int i,j=1,k;
    long long *s=calloc(EXACT,sizeof(long long));
    for (k=0;k<EXACT;k++){
        for (i=k,j=1;i<len;i+=EXACT) {
            s[k]+=cast(x[i])*j;
            j*=-7;
        }
    }
    hv newh={s};
    return newh;
}

int hvsame(hv a,hv b){
    int correct=0;
    for (int i=0;i<EXACT;i++){
        correct+=(a.s[i]==b.s[i]);
    }
    return (correct>=EXACT-1);
}

int main(){
    int n,j,k=0,l,s,res=0;
    scanf("%d%d%d",&n,&l,&s);
    while (n--){
        scanf("%s",ipt);
        hv newh=hash(ipt,l);
        for (j=0;j<k;j++){
            if (hvsame(totalhv[j],newh)){
                res++;
            }
        }
        totalhv[k++]=newh;
    }
    printf("%d\n",res);
    return 0;
}