#include <stdio.h>
#define CHAR 26
#define LENGTH 30000

/*
refer to P1819
*/

char str[LENGTH];
int nxt[LENGTH][CHAR];
int nxt1[LENGTH][CHAR];
int nxt2[LENGTH][CHAR];
long long f[LENGTH][LENGTH]

void build(char str[LENGTH]){
    char* s=str-1;
    for(int i=LENGTH-1;i>=0;i--){
        for(int j=1;j<=CHAR;j++) nxt[i][j]=nxt[i+1][j];
        nxt[i][s[i+1]-'a'+1]=i+1;
    }
}

long long dfs(int a,int b){
    if (f[a][b]) return f[a][b];
    for (int i=0;i<CHAR;i++){
        if (nxt1[a][i]&&nxt[b][i]){
            f[a][b]+=dfs(nxt1[a][i],nxt[b][i]);
        }
        if (a||b) f[a][b]++;
        return f[a][b];
    }

}