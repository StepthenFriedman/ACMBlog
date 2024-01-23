#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hashvalue{
    int head;int len;unsigned long long hash;
}hv;

int cast(char x){
    if (x>='a'&&x<='z') return x-'a';
    if (x>='A'&&x<='Z') return x-'A'+26;
    if (x>='0'&&x<='9') return x-'0'+52;
}

hv hash(char* x,int len){
    unsigned long long h=0,j=10000000000000000ULL;
    for (int i=1;i<=8&&i<len;i++,j/=100){
        h+=j*cast(x[i]);
    }
    hv hash={x[0],len,h};
    return hash;
}

hv ipth[100000];

unsigned long long power100(int x){
    unsigned long long r=1000000000000000000ULL;
    while (x--){
        r/=100;
    }
    return r;
}

int same(hv src,hv ask){
    if (src.head==ask.head && src.len>=ask.len){
        if (ask.len<=1) return 1;
        unsigned long long dif=src.hash-ask.hash;
        if (dif==0) return 1;
        if (dif>0){
            if (ask.len>=8) return 0;
            if (dif>power100(ask.len-1)/10) return 0;
            return 1;
        }
    }
    return 0;
}
int main(){
    int t;
    scanf("%d",&t);
    while (t--){
        int n,q,i,j;
        scanf("%d%d",&n,&q);
        for (i=0;i<n;i++){
            char *temp=malloc(10000);
            scanf("%s",temp);
            int len=strlen(temp);
            ipth[i]=hash(temp,len);
        }
        char *ask=malloc(10000);
        for (i=0;i<q;i++){
            scanf("%s",ask);
            hv newh=hash(ask,strlen(ask));
            int count=0;

            for (j=0;j<n;j++){
                if (same(ipth[j],newh)){
                    count++;
                }
            }
            printf("%d\n",count);
        }
    }
}