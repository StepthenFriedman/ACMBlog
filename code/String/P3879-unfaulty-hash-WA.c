#include<stdio.h>
#include<string.h>
/*
why WA?
*/

typedef struct hashvalue{
    int head,toe,len;
}hv;

char ipt[21];
int psglen[1000];
hv total[1000][260];
char ttlstr[1000][260][21];

hv hash(char* x){
    int len=strlen(x);
    //int h=x[((len-1)/5)]+7*x[((len-1)/5)*2]+49*x[((len-1)/5)*3]+343*x[((len-1)/5)*4]+7*343*x[((len-1)/5)*4];
    hv hash={x[0],x[len-1],len};
    return hash;
}

int same(hv a,hv b){
    return (a.len==b.len)&&(a.head==b.head)&&(a.toe==b.toe);
}

int main(){
    int n,m,i,j,k,l=0;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%d",&l);
        psglen[i]=l;
        for (j=0;j<l;j++){
            scanf("%s",ipt);
            total[i][j]=hash(ipt);
            strcpy(ttlstr[i][j],ipt);
        }
    }
    scanf("%d",&m);
    for (i=0;i<m;i++){
        int ls=1;
        scanf("%s",ipt);
        hv newh=hash(ipt);
        for (j=0;j<n;j++){
            for (k=0;k<psglen[j];k++){
                if (!strcmp(ttlstr[j][k],ipt)){//if (same(newh,total[j][k])&&!strcmp(ttlstr[j][k],ipt))
                    printf(" %d"+ls,j+1);
                    ls=0;
                    goto next;
                }
            }
            next:;
        }
        putchar('\n');
    }
    return 0;
}