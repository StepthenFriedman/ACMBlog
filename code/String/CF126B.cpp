#include <bits/stdc++.h>
using namespace std;

vector<int> kmp(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j>0 && s[i]!=s[j]) j=pi[j-1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
        if (i>sublen+1 && pi[i]==sublen){
            cout<<i-sublen*2+1<<'\n';
        }
    }
}

string s;
int main(){
    std::ios::sync_with_stdio(0);
    cin>>s;
    vector<int>=kmp(s);
}