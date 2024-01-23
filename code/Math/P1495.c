#include <stdio.h>

int ai[10],bi[10],n;

typedef struct K{
    int k1,k2;
}K;

typedef struct A{
    int a1,a2,mod;
}A;

A a;

K solve(A a){
    if (a.a1==a.a2+a.mod){
        K k={1,1};
        //printf("1: %d*%d=%d*%d+%d\n",a.a1,k.k1,a.a2,k.k2,a.mod);
        return k;
    }
    if (a.mod==0){
        K k={a.a2,a.a1};
        //printf("2: %d*%d=%d*%d+%d\n",a.a1,k.k1,a.a2,k.k2,a.mod);
        return k;
    }
    if (a.a1<a.a2){
        //printf("3: %d*?=%d*?+%d\n",a.a1,a.a2,a.mod);
        int add=0;
        a.a2-=a.a1;
        if (a.mod>=a.a2){
            add=a.mod/a.a2;
            a.mod%=a.a2;
        }
        K k=solve(a);
        if (add) k.k2-=add;
        k.k1+=k.k2;
        //printf("3: %d*%d=%d*%d+%d\n",a.a1,k.k1,a.a2,k.k2,a.mod);
        return k;
    }

/*
3: 1*?=3*?+2
2: 1*2=2*1+0
3: 1*2=3*0+2
*/
    if (a.a1>a.a2){
        //printf("4: %d*?=%d*?+%d\n",a.a1,a.a2,a.mod);
        a.a1-=a.a2;
        K k=solve(a);
        k.k2+=k.k1;
        //printf("4: %d*%d=%d*%d+%d\n",a.a1,k.k1,a.a2,k.k2,a.mod);
        return k;
    }
}

void merge(int i){
    if (i==n-1) return;
    
}

int main(){
    int i;
    /*scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%d%d",a+i,b+i);

    }*/
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    A ai={a,b,c};
    K k=solve(ai);
    printf("%d %d\n",k.k1,k.k2);
}