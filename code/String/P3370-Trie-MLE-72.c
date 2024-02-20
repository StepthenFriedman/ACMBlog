#include<stdio.h>
#include<string.h>

char temp[1600];
int nxt[300000][63]={0},count=0;
int exist[300000]={0};
int res=0;

int cast(char x){
    if (x>='a'&&x<='z') return x-'a';
    if (x>='A'&&x<='Z') return x-'A'+26;
    if (x>='0'&&x<='9') return x-'0'+52;
}

void insert(){
    int ptr=0,i,c;
    for (i=0;temp[i]!='\0';i++){
        c=cast(temp[i]);
        if (!nxt[ptr][c]) nxt[ptr][c]=++count;
        ptr=nxt[ptr][c];
    }
    if (!exist[ptr]) res++;
    exist[ptr]=1;
}

int main(){
    int n;
    scanf("%d",&n);
    while (n--){
        scanf("%s",temp);
        insert();
    }
    printf("%d\n",res);
    return 0;
}