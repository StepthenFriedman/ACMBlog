#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+7;

struct State{
	int len,fa,ch[26];
}st[N<<1];

int lst=1,cnt=1;
string str1,str2;

inline void ins(int c){
	int p=lst,np=lst=++cnt;
	st[np].len=st[p].len+1;
	for(;p&&!st[p].ch[c];p=st[p].fa) st[p].ch[c]=np;
	if(!p) return (void)(st[np].fa=1);
	int q=st[p].ch[c];
	if(st[q].len==st[p].len+1) return (void)(st[np].fa=q);
	int nq=++cnt;st[nq]=st[q];st[nq].len=st[p].len+1,st[q].fa=st[np].fa=nq;
	for(;p&&st[p].ch[c]==q;p=st[p].fa) st[p].ch[c]=nq;
}

int calc(int n){
	int p=1,ans=0,len=0;
	for(int i=0;i<n;i++){ //子串开始位置 
		int c=str2[i]-'a';
		if(st[p].ch[c]) len++,p=st[p].ch[c]; 
		else{
			for(;p&&!st[p].ch[c];p=st[p].fa); 
			if(p) len=st[p].len+1,p=st[p].ch[c]; //匹配下一个字符 
			else len=0,p=1; //返回初始状态 
		}
		ans=max(ans,len);
	}
	return ans;
}

signed main(){
	cin>>str1;
	cin>>str2;
	int n1=str1.length(),n2=str2.length();
	for(int i=0;i<n1;i++) ins(str1[i]-'a');
	cout<<calc(n2)<<"\n";
	return 0; 
}