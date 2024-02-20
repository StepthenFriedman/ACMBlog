#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define ll long long
#define MOD 100000000007

typedef struct hashvalue{
    ll a1,a2,b1,b2;
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
    ll a1=0,a2=0,b1=0,b2=0;
    for (int i=0;i<len;i+=2) {
        a1=(a1*29+cast(x[i]))%MOD;
        a2=(a2*31+cast(x[i+1]))%MOD;
    }
    for (int i=0;i<len/2;i++){
        b1=(b1*29+cast(x[i]))%MOD;
        b2=(b2*31+cast(x[i+len/2]))%MOD;
    }
    hv newh={a1,a2,b1,b2};
    return newh;
}

int hvsame(hv a,hv b){
    return ((a.a1==b.a1)+(a.a2==b.a2)>=1)&&((a.b1==b.b1)+(a.b2==b.b2)>=1);
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