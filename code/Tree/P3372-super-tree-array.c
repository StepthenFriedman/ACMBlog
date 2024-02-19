#include <stdio.h>
#define MAXN 100005
#define ll long long
#define lowbit(x) ((x)&(-x))
#define father(x) ((x)+lowbit(x))
#define left(x) ((x)-(lowbit(x)))
#define int long long

int tree[MAXN]={0};
int tree2[MAXN]={0};
int perfix[MAXN]={0};

int m,n;

void add(int x, int k) {
	for (int i=x;i<=n;i=father(i))
		tree[i]+=k,tree2[i]+=k*x;
}

int query1(int x){	
	int res=0;
	for(int i=x;i>0;i=left(i))
	    res+=tree[i];
	return res;
}
int query2(int x){	
	int res=0;
	for(int i=x;i>0;i=left(i))
	    res+=tree2[i];
	return res;
}

int query(int x){
	return query1(x)*(x+1)-query2(x)+perfix[x];
}

#define query_period(l,r) (query(r)-query((l)-1))

int read(){
	char c=getchar();
	int f=1,x=0;
	while(c<'0'||c>'9'){
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+(c^'0');
		c=getchar();
	}
	return x*f;
}



signed main(){
	int i,j,x,y,k;
	freopen("../../data/P3372.in","r",stdin);
	n=read(),m=read();
	for (i=1;i<=n;i++) perfix[i]=read()+perfix[i-1];
	while (m--){
		if (read()==1){
			x=read(),y=read(),k=read();
		    add(x,k);
			add(y+1,-k);
		}else{
			x=read();y=read();
			printf("%lld\n",query_period(x,y));
		}
	}
	return 0;
}