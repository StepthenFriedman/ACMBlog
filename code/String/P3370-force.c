#include<stdio.h>
#include<string.h>

char total[10000][1600];
char ipt[1600];
int main(){
    int n,j,k=0;
    scanf("%d",&n);
    while (n--){
        scanf("%s",ipt);
        for (j=0;j<k;j++){
            if (!strcmp(total[j],ipt)){
                goto next;
            }
        }
        strcpy(total[k++],ipt);
        next:;
    }
    printf("%d\n",k);
    return 0;
}