#include <stdio.h>
#define LEN 160
int nxt1[LEN][26]={0},nxt2[LEN][26]={0};
char s1[LEN],s2[LEN];
long long f[LEN][LEN]={0};

long long dfs(int x,int y){
    if(f[x][y]) return f[x][y];
    for(int i=0;i<26;i++){
        if(nxt1[x][i]&&nxt2[y][i]){
            f[x][y]+=dfs(nxt1[x][i],nxt2[y][i]);
        }
    }
    if (x||y) f[x][y]++;
    return f[x][y];
}

int main(){
    int n,i,j;
    scanf("%d%s%s",&n,s1+1,s2+1);
    for(i=n-1;i>=0;i--){
        for(j=0;j<26;j++) {
            nxt1[i][j]=nxt1[i+1][j];
            nxt2[i][j]=nxt2[i+1][j];
        }
        nxt1[i][s1[i+1]-'a']=i+1;
        nxt2[i][s2[i+1]-'a']=i+1;
    }
    printf("%lld\n",dfs(0,0));
}