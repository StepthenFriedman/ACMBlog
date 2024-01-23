#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define min(x,y) (x)<(y)?(x):(y)

int cast(char x){
    if (x>='a'&&x<='z') return x-'a';
    if (x>='A'&&x<='Z') return x-'A'+26;
    if (x>='0'&&x<='9') return x-'0'+52;
}

int nxt[100000][62]={0},count=0;
int exist[100000]={0};
char temp[100000];

int insert(){
    int ptr=0,i,c;
    for (i=0;temp[i]!='\0';i++){
        c=cast(temp[i]);
        if (!nxt[ptr][c]){
            nxt[ptr][c]=++count;
        }
        exist[ptr]++;
        ptr=nxt[ptr][c];
    }
}

int find(){
    int ptr=0,i,c;
    int match=INT_MAX;
    for (i=0;temp[i]!='\0';i++){
        c=cast(temp[i]);
        match=min(match,exist[ptr]);

        if (!nxt[ptr][c]) return 0;
        ptr=nxt[ptr][c];
    }
    return match;
}

int main(){
    int t;
    scanf("%d",&t);
    while (t--){
        int n,q,i,j;
        count=0;
        memset(nxt,0,100000*62*sizeof(int));
        memset(exist,0,100000*sizeof(int));
        scanf("%d%d",&n,&q);
        for (i=0;i<n;i++){
            scanf("%s",temp);
            insert();
        }
        for (i=0;i<q;i++){
            scanf("%s",temp);
            printf("%d\n",find());
        }
    }
}