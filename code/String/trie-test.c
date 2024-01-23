#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cast(char x){
    if (x>='a'&&x<='z') return x-'a';
    if (x>='A'&&x<='Z') return x-'A'+26;
    if (x>='0'&&x<='9') return x-'0'+52;
}

int nxt[100000][26+26+10]={0},count=0;
char temp[100000];

int insert(int len){
    int ptr=0,i,c;
    for (i=0;i<len;i++){
        c=cast(temp[i]);
        if (!nxt[ptr][c]){
            nxt[ptr][c]=++count;
        }
        ptr=nxt[ptr][c];
    }
}

int find(int len){
    int ptr=0,i,c;
    for (i=0;i<len;i++){
        c=cast(temp[i]);
        if (!nxt[ptr][c]) return 0;
        ptr=nxt[ptr][c];
    }
    return 1;
}

int main(){
    int t;
    int n,q,i,j;
    scanf("%d%d",&n,&q);
    for (i=0;i<n;i++){
        scanf("%s",temp);
        insert(strlen(temp));
    }
    for (i=0;i<q;i++){
        scanf("%s",temp);
        printf("%d\n",find(strlen(temp)));
    }
}