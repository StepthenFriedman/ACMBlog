const int N = 1e6 + 10;
const int mod = 998244353;
int n;
LL f[N], ynum[N];
/*
most understandable.
*/
//bool edd;
int main(){
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
//	cerr << (&edd - &stt) / 1024.0 / 1024.0 << endl;
	rd(n);
	rep(i, 1, n) for(int j = i; j <= n; j += i) ynum[j]++;
	f[1] = 1;
	rep(i, 2, n) f[i] = (((f[i - 1] << 1) + ynum[i] - ynum[i - 1]) % mod + mod) % mod;
	prf("%d\n", f[n]);
	return 0;
}