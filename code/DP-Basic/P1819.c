#include <stdio.h>
#define LEN 151
#define MOD 100000000
int nxt1[LEN][26]={0},nxt2[LEN][26]={0},nxt3[LEN][26]={0};
char s1[LEN],s2[LEN],s3[LEN];
long long f[LEN][LEN][LEN]={0};

long long dfs(int x,int y,int z){
    if(f[x][y][z]) return f[x][y][z];
    for(int i=0;i<26;++i)
        if(nxt1[x][i]&&nxt2[y][i]&&nxt3[z][i])
            f[x][y][z]=(f[x][y][z]+dfs(nxt1[x][i],nxt2[y][i],nxt3[z][i]))%MOD;
    if (x||y||z) f[x][y][z]++;
    return f[x][y][z];
}

int main(){
    int n,i,j;
    scanf("%d%s%s%s",&n,s1+1,s2+1,s3+1);
    for(i=n-1;i>=0;i--){
        for(j=0;j<26;j++) {
            nxt1[i][j]=nxt1[i+1][j];
            nxt2[i][j]=nxt2[i+1][j];
            nxt3[i][j]=nxt3[i+1][j];
        }
        nxt1[i][s1[i+1]-'a']=i+1;
        nxt2[i][s2[i+1]-'a']=i+1;
        nxt3[i][s3[i+1]-'a']=i+1;
    }
    printf("%lld\n",dfs(0,0,0));
}