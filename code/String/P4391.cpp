#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

vector<int> kmp(string s,int n) {
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j>0 && s[i]!=s[j]) j=pi[j-1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

string s;
int main(){
    int i,n;
    std::ios::sync_with_stdio(0);
    cin>>n>>s;
    vector<int> pi=kmp(s,n);
    int len=n-pi[n-1];
    cout<<len<<endl;
    return 0;
}
