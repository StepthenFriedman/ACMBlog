#include <bits/stdc++.h>
#include <cstdio>
unsing namespace std;

int cast(char x){
    if (x>='a'&&x<='z') return x-'a';
    if (x>='A'&&x<='Z') return x-'A'+26;
    if (x>='0'&&x<='9') return x-'0'+52;
}

int nxt[32][2]={0},count=0;
int exist[32]={0};
unsigned long long temp;

void write(int x){
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
    return;
}

void insert(){
    int ptr=0,i,c;
    for (i=0;i<32;i++){
        c=temp[i];
        if (!nxt[ptr][c]){
            nxt[ptr][c]=++count;
        }
        ptr=nxt[ptr][c];
        exist[ptr]++;
    }
}

int find(){
    int ptr=0,i,c;
    for (i=0;i<32;i++){
        c=temp[i];
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
        memset(nxt,0,32*2*sizeof(int));
        memset(exist,0,32*sizeof(int));
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