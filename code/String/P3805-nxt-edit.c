#include <stdio.h>
#include <string.h>
#define MAXLEN 11000002

char ipt[MAXLEN];

int nxt1[MAXLEN][26]={0},
    nxt2[MAXLEN][26]={0};

long long dfs(int x,int y,int z){
    if(f[x][y]) return f[x][y];
    for(int i=0;i<26;++i)
        if(nxt1[x][i]&&nxt2[y][i]&&nxt3[z][i])
            f[x][y][z]=(f[x][y][z]+dfs(nxt1[x][i],nxt2[y][i],nxt3[z][i]))%MOD;
    if (x||y||z) f[x][y][z]++;
    return f[x][y][z];
}

int main(){
    scanf("%s",ipt+1);
    int n=strlen(ipt+1);
    for(i=n-1;i>=0;i--){
        for(j=0;j<26;j++) {
            nxt1[i][j]=nxt1[i+1][j];
        }
        nxt1[i][ipt[i+1]-'a']=i+1;
    }
    for(i=1;i<=n;i++){
        for(j=0;j<26;j++) {
            nxt2[i][j]=nxt2[i-1][j];
        }
        nxt2[i][ipt[i-1]-'a']=i-1;
    }
}