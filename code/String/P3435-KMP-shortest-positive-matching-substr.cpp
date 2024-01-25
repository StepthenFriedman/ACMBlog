#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define int long long
long long ans=0;

void kmp(string s,int n) {
    vector<int> pi(n);
    int Q,i,j;
    for (i=1;i<n;i++) {
        j = pi[i-1];
        while (j>0 && s[i]!=s[j]) j=pi[j-1];
        if (s[i]==s[j]) j++;
        pi[i]=j;
    }
    for (i=1;i<n;i++){
        j=i+1;
        while (pi[j-1]) j=pi[j-1];
        if (pi[i]) pi[i]=j;
        ans+=i+1-j;
    }
}


string s;
signed main(){
    int i,n;
    //freopen("../../data/P3435_3.in","r",stdin);
    std::ios::sync_with_stdio(0);
    cin>>n>>s;
    kmp(s,n);
    cout<<ans<<endl;
    return 0;
}
