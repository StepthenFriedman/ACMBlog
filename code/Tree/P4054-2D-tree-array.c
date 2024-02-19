#include <stdio.h>
#define MAXN 301
#define ll long long
#define lowbit(x) ((x)&(-x))
#define father(x) ((x)+lowbit(x))
#define left(x) ((x)-(lowbit(x)))

int tree[MAXN][MAXN][100]={0};
int map[MAXN][MAXN];

int m,n,q;

void add(int x, int y, int count, int type) {
	for (int i=x;i<=n;i=father(i))
		for (int j=y;j<=m;j=father(j))
			tree[i][j][type]+=count;
}

int query(int x,int y,int type){	
	int res=0;
	for(int i=x;i>0;i=left(i))
		for(int j=y;j>0;j=left(j))
	    	res+=tree[i][j][type];
	return res;
}

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



int main(){
	int i,j,ipt;
	freopen("../../data/P4054.in","r",stdin);
	n=read(),m=read();
	for (i=1;i<=n;i++) for (j=1;j<=m;j++) {
		ipt=read();
		map[i][j]=ipt;
		add(i,j,1,ipt);
	}
	q=read();
	int x1,y1,x2,y2;
	while (q--){
		if (read()==1){
			x1=read();y1=read();
			
			add(x1,y1,-1,map[x1][y1]);
			map[x1][y1]=read();
			add(x1,y1,1,map[x1][y1]);
		}else{
			
			x1=read();x2=read();
			y1=read();y2=read();
			ipt=read();
			printf("%d\n",query(x2,y2,ipt)-query(x2,y1-1,ipt)-query(x1-1,y2,ipt)+query(x1-1,y1-1,ipt));
		}
	}
}