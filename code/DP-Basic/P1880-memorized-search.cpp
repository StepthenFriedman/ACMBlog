#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
/*
this algorithm stores the result in a map after computing,
thus dulplicated computing was avoided.
*/

const int INF=0x7fffffff;
int n,m,ans1,ans2;
int A[205],f1[205][205],f2[205][205];
int dfs1(int L,int R){
    if(f1[L][R])return f1[L][R];
    if(L==R)    return f1[L][R]=0;
    int res=INF;
    for(int k=L;k<R;k++)
        res=min(res,dfs1(L,k)+dfs1(k+1,R)+A[R]-A[L-1]);
    return f1[L][R]=res;
}
int dfs2(int L,int R){
    if(f2[L][R])return f2[L][R];
    if(L==R)    return f2[L][R]=0;
    int res=0;
    for(int k=L;k<R;k++)
        res=max(res,dfs2(L,k)+dfs2(k+1,R)+A[R]-A[L-1]);
    return f2[L][R]=res;
}
int main(){
    std::ios::sync_with_stdio(false);//speed up input
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>A[i];
        A[i+n]=A[i];
    }
    for(int i=1;i<=2*n;i++)
        A[i]+=A[i-1];
    dfs1(1,2*n);dfs2(1,2*n);
    ans1=INF;    ans2=0;
    for(int i=1;i<=n;i++){
        ans1=min(f1[i][n+i-1],ans1);
        ans2=max(f2[i][n+i-1],ans2);
    }
    cout<<ans1<<"\n"<<ans2;
    return 0;
}