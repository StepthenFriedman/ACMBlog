#include<stdio.h>
#include<string.h>

char ipt[21];
int psglen[1000];
char ttlstr[1000][260][21];

char res[100000]={'\0'};
char temp[10];

int main(){
    int n,m,i,j,k,l=0;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%d",&l);
        psglen[i]=l;
        for (j=0;j<l;j++){
            scanf("%s",ttlstr[i][j]);
        }
    }
    scanf("%d",&m);
    while (m--){
        int ls=1;
        scanf("%s",ipt);
        for (i=0;i<n;i++){
            for (j=0;j<psglen[i];j++){
                if (!strcmp(ttlstr[i][j],ipt)){
                    sprintf(temp," %d"+ls,i+1);
                    strcat(res+strlen(res),temp);
                    //printf(" %d"+ls,i+1);
                    ls=0;
                    goto next;
                }
            }
            next:;
        }
        //putchar('\n');
        strcat(res+strlen(res),"\n");
    }
    printf("%s",res);
    return 0;
}