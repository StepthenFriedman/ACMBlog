#include<stdio.h>  
#define maxn 32005 
#define max(x,y) x>y?x:y
int m,n,mw[maxn],mv[maxn],fw[maxn][3],fv[maxn][3],f[maxn],v,p,q;  
int main(){  
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){  
        scanf("%d%d%d",&v,&p,&q);
        if(!q){
            mw[i]=v;
            mv[i]=v*p; 
        }  
        else{
            fw[q][0]++;
            fw[q][fw[q][0]]=v;
            fv[q][fw[q][0]]=v*p;
        }  
    }  
    for(int i=1;i<=m;i++)  
    for(int j=n;j>=mw[i];j--){
        f[j]=max(f[j],f[j-mw[i]]+mv[i]);  
        if(j>=mw[i]+fw[i][1])f[j]=max(f[j],f[j-mw[i]-fw[i][1]]+mv[i]+fv[i][1]);  
        if(j>=mw[i]+fw[i][2])f[j]=max(f[j],f[j-mw[i]-fw[i][2]]+mv[i]+fv[i][2]);  
        if(j>=mw[i]+fw[i][1]+fw[i][2])  
        f[j]=max(f[j],f[j-mw[i]-fw[i][1]-fw[i][2]]+mv[i]+fv[i][1]+fv[i][2]);
        for (int j=0;j<=n;j++) printf("%d ",f[j]); putchar('\n');  
    }  
    printf("%d\n",f[n]);
    return 0;  
} 