#include<stdio.h>
#include<string.h>

char total[30000][201];
char ipt[201];

int same(char*a,char*b,int l){
    int count=0,i;
    for (i=0;i<l;i++){
        if (a[i]!=b[i]){
            if (count==1) return 0;
            else if (count==0) count++;
        }
    }
    return 1;
}

int main(){
    int n,j,k=0,l,s,res=0;
    scanf("%d%d%d",&n,&l,&s);
    while (n--){
        scanf("%s",ipt);
        for (j=0;j<k;j++){
            if (same(total[j],ipt,l)){
                res++;
            }
        }
        strcpy(total[k++],ipt);
        next:;
    }
    printf("%d\n",res);
    return 0;
}