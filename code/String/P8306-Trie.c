#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cast(char x){
    if (x>='a'&&x<='z') return x-'a';
    if (x>='A'&&x<='Z') return x-'A'+26;
    if (x>='0'&&x<='9') return x-'0'+52;
}

int nxt[3000005][63]={0},count=0;
int exist[3000005]={0};
char temp[3000005];

void write(int x){
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
    return;
}

void insert(){
    int ptr=0,i,c;
    for (i=0;temp[i]!='\0';i++){
        c=cast(temp[i]);
        if (!nxt[ptr][c]){
            nxt[ptr][c]=++count;
        }
        ptr=nxt[ptr][c];
        exist[ptr]++;
    }
}

int find(){
    int ptr=0,i,c;
    for (i=0;temp[i]!='\0';i++){
        c=cast(temp[i]);
        if (!nxt[ptr][c]) return 0;
        ptr=nxt[ptr][c];
    }
    return exist[ptr];
}

int main(){
    long long t;
    scanf("%lld",&t);
    while (t--){
        long long n,q,i,j;
        memset(nxt,0,count*63*sizeof(int));
        memset(exist,0,count*sizeof(int));
        /*
        the following would cause TLE:
        memset(nxt,0,3000005*63*sizeof(int));
        memset(exist,0,3000005*sizeof(int));
        */
        count=0;
        scanf("%lld%lld",&n,&q);
        for (i=0;i<n;i++){
            scanf("%s",temp);
            insert();
        }
        for (i=0;i<q;i++){
            scanf("%s",temp);
            write(find());
            putchar('\n');
        }
    }
}