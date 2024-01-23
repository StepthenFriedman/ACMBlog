#include<stdio.h>
#include<string.h>
#define abs(x,y) (x)>(y)?(x)-(y):(y)-(x)

typedef struct hashvalue{
    long long even,odd;
}hv;

hv totalhv[30000];
char totalstr[30000][201];
char ipt[201];

char cast(char x){
    if (x>='a'&&x<='z') return x-'a'+1;
    if (x>='A'&&x<='Z') return x-'A'+27;
    if (x>='0'&&x<='9') return x-'0'+53;
    if (x=='_') return 63;
    if (x=='@') return 64;
}

hv hash(char* x,int len){
    int i,j=1,even=0,odd=0;
    for (i=0;i<len;i+=2) {
        even+=cast(x[i])*j;
        j*=7;
    }
    j=1;
    for (i=1;i<len;i+=2) {
        odd+=cast(x[i])*j;
        j*=13;
    }
    hv newh={even,odd};
    return newh;
}

int hvsame(hv a,hv b){
    return (a.even==b.even)||(a.odd==b.odd);
}

int same(char*a,char*b,hv ah,hv bh,int l){
    if (hvsame(ah,bh)) {
        int count=0,i;
        for (i=0;i<l;i++){
            if (a[i]!=b[i]){
                if (count==1) return 0;
                else if (count==0) count++;
            }
        }
    }else return 0;
    return 1;
}
int main(){
    int n,j,k=0,l,s,res=0;
    scanf("%d%d%d",&n,&l,&s);
    while (n--){
        scanf("%s",ipt);
        hv newh=hash(ipt,l);
        for (j=0;j<k;j++){
            if (same(totalstr[j],ipt,totalhv[j],newh,l)){
                res++;
            }
        }
        totalhv[k]=newh;
        strcpy(totalstr[k++],ipt);
    }
    printf("%d\n",res);
    return 0;
}