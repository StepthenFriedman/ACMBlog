#include<bits/stdc++.h>
#define ls o<<1
#define rs o<<1|1
using namespace std;
const int maxn=6e5+5;
int T;
int n,m,q[maxn>>1],ans;
int t[maxn<<2];
void pushup(int o){
	t[o]=t[ls]+t[rs];
	return ;
}
void update(int o,int l,int r,int pos,int val){
	if(l==r){
		t[o]+=val;
		return ;
	}
	int mid=l+r>>1;
	if(pos<=mid)update(ls,l,mid,pos,val);
	else update(rs,mid+1,r,pos,val);
	pushup(o);
}
void query(int o,int l,int r,int x,int y){
	if(x<=l&&r<=y){
		ans+=t[o];
		return ;
	}
	int mid=l+r>>1;
	if(x<=mid)query(ls,l,mid,x,y);
	if(y>mid)query(rs,mid+1,r,x,y);
	return ;
}
int mn[maxn>>1],mx[maxn>>1],pos[maxn>>1],cnt;
int main(){
	T=1;
    freopen("../../data/CF1288E.in","r",stdin);
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			pos[i]=i+m;
			update(1,0,n+m,i+m,1);
			mn[i]=mx[i]=i;
		}
		cnt=m;
		for(int i=1;i<=m;i++){
			cin>>q[i];
			mn[q[i]]=1;
			ans=0;
			query(1,0,n+m,0,pos[q[i]]);
			mx[q[i]]=max(mx[q[i]],ans);
			update(1,0,n+m,pos[q[i]],-1);
			pos[q[i]]=cnt;
			cnt--;
			update(1,0,n+m,cnt+1,1);
		}
		for(int i=1;i<=n;i++){
			ans=0;
			query(1,0,n+m,0,pos[i]);
			mx[i]=max(mx[i],ans);
		}
		for(int i=1;i<=n;i++){
			cout<<mn[i]<<' '<<mx[i]<<endl;
		}
	}
}