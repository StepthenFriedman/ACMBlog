#include <bits/stdc++.h>
#define int long long
#define LEN 500000

using namespace std;

int nxt[LEN][2]={0},cnt=0;
int exist[LEN]={0};
int temp[10005];
int L;

void insert(){
    int ptr=0,i,c;
    exist[0]++;
    for (i=0;i<L;i++){
        c=temp[i];
        if (!nxt[ptr][c]){
            nxt[ptr][c]=++cnt;
        }
        ptr=nxt[ptr][c];
        exist[ptr]++;
    }
}

int find(){
    int ptr=0,i,c,cutptr;
    int ans=exist[0];
    for (i=0;i<L;i++){
        c=temp[i];
        cutptr=nxt[ptr][!c];
        if (cutptr) ans-=exist[cutptr];
        if (!nxt[ptr][c]) return ans;
        ptr=nxt[ptr][c];
    }
    return ans;
}

signed main(){
    std::ios::sync_with_stdio(0);
    int M,N,i,j;
    cin>>M>>N;
    for (i=0;i<M;i++){
        cin>>L;
        for (j=0;j<L;j++){
            cin>>temp[j];
        }
        insert();
    }
    for (i=0;i<N;i++){
        cin>>L;
        for (j=0;j<L;j++){
            cin>>temp[j];
        }
        cout<<find()<<endl;
    }
    return 0;
}