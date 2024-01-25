#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define int long long
long long ans=0;

void kmp(string s,int n) {
    vector<int> pi(n);
    int Q;
    for (int i=1; i<n; i++) {
        int j = pi[i-1];
        while (j>0 && s[i]!=s[j]) j=pi[j-1];
        if (s[i]==s[j]) j++;
        pi[i]=j;
        Q=1+i-pi[i];
        Q=Q*(i/Q);
        /*
        this idea is completely wrong.
        */
        cout<<i<<' '<<pi[i]<<'\n';
        ans+=Q;
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
