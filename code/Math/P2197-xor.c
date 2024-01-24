#include <stdio.h>

int main(){
    int T,n,i,ipt;
    int res;
    scanf("%d",&T);
    while (T--){
        scanf("%d",&n);
        res=0;
        for (i=0;i<n;i++){
            scanf("%d",&ipt);
            res^=ipt;
        }
        if (res) printf("Yes\n");
        else printf("No\n");
    }
}