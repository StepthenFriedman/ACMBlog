#include<stdio.h>
#include<math.h>

int a[1000000];

void x(int n){
    int i,*j,amount,sqt,*st=&a[2];
    a[0]=2,a[1]=3,a[2]=5;
    for (amount=3,i=7;i<=n;i+=6){
        sqt=sqrt(i+4);
        for (j=st;*j<=sqt;j++) if (!(i%*j)) goto next1;
        a[amount++]=i;
        next1:;
        i+=4;
        for (j=st;*j<=sqt;j++) if (!(i%*j)) goto next2;
        a[amount++]=i;
        next2:;
        i-=4;
    }
}

int main(){
    int n,q,i,j;
    scanf("%d%d",&n,&q);
    x(n);
    for (i=0;i<q;i++){
        scanf("%d",&j);
        printf("%d\n",a[j-1]);
    }
}
