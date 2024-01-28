#include <bits/stdc++.h>
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
    cin>>s;
    n=(int)s.length();
    vector<int> pi=kmp(s,n);
    int len=pi[n-1];
    while (len>0){
        for (i=len-1;i<n-1;i++){
            if (pi[i]==len){
                goto ok;
            }
        }
        len=pi[len-1];
    }
    cout<<"Just a legend\n";
    return 0;
    ok:cout<<s.substr(0,len)<<'\n';
    return 0;
}