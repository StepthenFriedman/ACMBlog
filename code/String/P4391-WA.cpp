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
    if (n==1){
        cout<<"1\n";
        return 0;
    }
    vector<int> pi=kmp(s,n);
    int len=pi[n-1];
    if (pi[n-1]!=pi[n-2]+1){
        cout<<n<<endl;
        return 0;
    }
    i=n-1;
    while (pi[i]==pi[i-1]+1 && pi[i-1]!=0) {
        i--;
    }
    cout<<i<<endl;
    return 0;
}
