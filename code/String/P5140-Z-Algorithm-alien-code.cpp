#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=2e7;
string a,b;
vector<ll> z(MAXN),ext(MAXN);
ll z_function(string s) {
    int n=(int)s.length();
    //vector<ll> z(n);
    for (int i=1,l=0,r=0;i<n;i++){
        if (i<=r && z[i-l]<r-i+1){
            z[i]=z[i-l];
        }else{
            z[i] = max(0,r-i+1);
            while (i+z[i]<n && s[z[i]]==s[i+z[i]]) z[i]++;
        }
        if (i+z[i]-1>r) l=i, r=i+z[i]-1;
    }
    ll res=0;
    z[0]=n;
    for (int i=1;i<=n;i++){
        res^=i*(z[i-1]+1);
    }
    return res;
}
/*
ll z_function_2(string a,string b) {
    int na=(int)a.length();
    int nb=(int)b.length();
    int i=0,l,r;
    while (a[i]==b[i] && i<na && i<nb) i++;
    p[0]=i;
    for (i=1,l=0,r=0;i<na;i++){
        r=l+p[l]-1;
        l=z[i-l];
        if(i + l <= p) ext[i] = l;
		else
		{
			int j = max(0, p - i + 1);
			while(i + j < la && j < lb && a[i + j] == b[j]) j++;
			ext[i] = j;
			k = i;
		}
    }
    ll res=0;
    for (i=1;i<=na;i++){
        res^=i*(p[i-1]+1);
    }
    return res;
}*/
ll exkmp(string a, string b){
	int la = a.length(), lb = b.length();
	int p = 0, k = 0, l;
	while(p < la && p < lb && a[p] == b[p]) p++;
	ext[0] = p;
	for(int i = 1; i < la; i++)
	{
		p = k + ext[k] - 1;
		l = z[i - k];
		if(i + l <= p) ext[i] = l;
		else
		{
			int j = max(0, p - i + 1);
			while(i + j < la && j < lb && a[i + j] == b[j]) j++;
			ext[i] = j;
			k = i;
		}
	}
    ll res=0;
    for (int i=1;i<=la;i++){
        res^=i*(ext[i-1]+1);
    }
    return res;
}

int main(){
    cin>>a>>b;
    cout<<z_function(b)<<'\n'<<exkmp(a,b)<<'\n';
    return 0;
}