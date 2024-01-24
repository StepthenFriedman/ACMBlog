#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int arr[300005];
int move[300005];
int exit[300005];

int main(){
    int q,n,i,j;
    scanf("%d",&q);
    while (q--){
        scanf("%d",&n);
        memset(move,0,sizeof(int)*300005);
        memset(exit,0,sizeof(int)*300005);
        for (i=0;i<n;i++){
            scanf("%d",arr+i);
            exit[arr[i]]=1;
        }
        isort(arr,n,sizeof(int),cmp);
        for (i=0;i<n;i++){
            printf("%d ",arr[i]);
        }putchar('\n');
    }
}