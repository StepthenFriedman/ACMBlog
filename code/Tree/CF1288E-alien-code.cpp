#include <bits/stdc++.h>
using namespace std;

//the key problem to difference array.

int read()
{
    char s;
    int k=0,base=1;
    while((s=getchar())!='-'&&s!=EOF&&!(s>='0'&&s<='9'));
    if(s==EOF)exit(0);
    if(s=='-')base=-1,s=getchar();
    while(s>='0'&&s<='9')
    {
        k=k*10+(s-'0');
        s=getchar();
    }
    return k*base;
}

const int MAXN = 600005;
int n, m, mini[MAXN], maxi[MAXN], c[MAXN], pos[MAXN];
void update(int x, int v) {for(; x <= n+m; x += (x&-x)) c[x] += v;}
//change the value in [x,n].

//normal comperhension: change the value of x.

void ckmax(int &a,int b){
	if (a<b) a=b;
}
int query(int x) {int ans = 0;for(; x; x -= (x&-x)) ans += c[x];return ans;}
//query the value of x.
//to watch the whole array, print query(x) in [1,n].

//normal comperhension: query the sum of [1,x].
//to watch the whole array, print query(x)-query(x-1) in [1,n].

signed main()
{
	freopen("../../data/CF1288E.in","r",stdin);
	cin >> n >> m;
	for(int i=1;i<=n;i++) mini[i] = maxi[i] = i, 
		pos[i] = m+i, //insert m blocks before the first messsage.
		update(pos[i], 1);
	int now = m;
	
	int dbg=m+n;

	while (m--){
		int i = read(); mini[i] = 1;
		ckmax(maxi[i], query(pos[i]));
		update(pos[i], -1); 
		for (int j=1;j<=dbg;j++) cout<<query(j)<<' ';
		cout<<endl;
		pos[i] = now--;
		update(pos[i], 1);
		for (int j=1;j<=dbg;j++) cout<<query(j)<<' ';
		cout<<endl<<endl;
	}
	for(int i=1;i<=n;i++) ckmax(maxi[i], query(pos[i]));
	for(int i=1;i<=n;i++) printf("%d %d\n", mini[i], maxi[i]);
    return 0;
}
