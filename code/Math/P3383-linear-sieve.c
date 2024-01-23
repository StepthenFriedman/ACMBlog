#include<stdio.h>
#include<math.h>
#define LEN 10000

int a[LEN]={0};
int b[1000000];

void x(int n){
    int i=2,j,pass;
    a[0]=a[1]=1;

    next:
    pass=0;
    for (j=i+i;j<=n;j+=i) if (!a[j]) {
        a[j]=1;pass=1;
    }
    i++;
    while (a[i]) i++;
    if (pass) goto next;
    i=j=0;
    while (1){
        i++;
        while (a[i]) i++;
        if (i>=n) return;
        b[j++]=i;
    }
}

int main(){
    int n,q,i,j;
    scanf("%d%d",&n,&q);
    x(n);
    for (i=0;i<q;i++){
        scanf("%d",&j);
        printf("%d\n",b[j-1]);
    }
}
