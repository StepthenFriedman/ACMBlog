#include <cstdio>
#define MAXN 500005
#define ll long long
#define lowbit(x) ((x)&(-x))
#define father(x) ((x)+lowbit(x))
#define left(x) ((x)-(lowbit(x)))

class tree_array{
    int n;
    ll tree[MAXN]={0};

    //单点修改
    void add(ll i,ll num){
        for(;i<=n;i=father(i)) tree[i]+=num;
    }

    //区间查询
    ll ask_period(ll i){
        ll ans=0;
        for(;i>=1;i=left(i)) ans+=tree[i];
        return ans;
    }

    //差分版
    //区间修改
    void add_period(ll i,ll j,ll num){
        add(i,num);add(j+1,-num);
    }

    //单点查询
    ll ask(ll i){
        ll ans=0;
        for(;i>=1;i=left(i)) ans+=tree[i];
        return ans;
        //return ans+arr[i]
    }
};

int main(){
}