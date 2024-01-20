#include <stdio.h>

int main(){
    for(int i=n-1;i>=0;--i){
        for(int j=1;j<=26;++j) nxt[i][j]=nxt[i+1][j];
        nxt[i][s[i+1]-'a'+1]=i+1;
    }
    return
}