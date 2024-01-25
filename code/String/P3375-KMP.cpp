#include <bits/stdc++.h>
#define MAXN 1000010
using namespace std;

void output1(string s,int sublen) {
    int n = (int)s.length();
    int pi[n];
    //cout<<"sublen:"<<sublen<<endl;
    memset(pi,0,sizeof(int)*n);
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

void output2(string s,int n) {
    int pi[n];
    memset(pi,0,sizeof(int)*n);
    cout<<0<<' ';
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j>0 && s[i]!=s[j]) j=pi[j-1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
        cout<<pi[i]<<' ';
    }
}

string s1,s2,s3;
int main(){
    std::ios::sync_with_stdio(0);
    cin>>s1>>s2;
    int sublen=s2.length();
    s3=s2+'#'+s1;
    //cout<<s3<<'\n';
    output1(s3,sublen);
    output2(s2,sublen);
}