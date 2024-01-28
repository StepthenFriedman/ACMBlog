#include <stdio.h>
#define ll long long
#define max(x,y) (x)>(y)?(x):(y)
int nxt[100000000][2]={0},cnt=0;
ll map[100000]={0};

char get_i(ll x,int i){
    return !!(x & (1LL<<i));
}

void insert(ll ins){
    int ptr=0,i,c;
    for (i=31;i>=0;i--){
        c=get_i(ins,i);
        if (!nxt[ptr][c]){
            nxt[ptr][c]=++cnt;
        }
        ptr=nxt[ptr][c];
    }
}

ll find(ll x){
    ll ptr=0,i,res=0;
    char c;
    for (i=31;i>=0;i--){
        c=get_i(x,i);
        if (nxt[ptr][!c]){
            ptr=nxt[ptr][!c],res<<=1,res++;
        }
        else if (nxt[ptr][c]){
            ptr=nxt[ptr][c],res<<=1;
        }
        else printf("!corrupted tree!\n");
    }
    return res;
}

int main(){
    ll n,i,res=0,temp;
    freopen("../../data/P4551_4.in","r",stdin);
    scanf("%lld",&n);
    for (i=1;i<n;i++){
        int n1,n2;
        scanf("%d%d%lld",&n1,&n2,&temp);
        map[n2]=map[n1]^temp;
        insert(map[n2]);
        //printf("get %d:%lld\n",n2,map[n2]);
    }
    for (i=1;i<=n;i++){
        //printf("%lld\n",map[i]);
    }
    for (i=0;i<n;i++){
        res=max(res,find(map[i]));
    }
    printf("%lld\n",res);
}