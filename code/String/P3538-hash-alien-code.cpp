#include <cstdio>
#include <cctype>
#include <vector>

using namespace std;

template<typename T> inline void read(T &x) {
	x = 0; T k = 1; char in = getchar();
	while (!isdigit(in)) { if (in == '-') k = -1; in = getchar(); }
	while (isdigit(in)) x = x * 10 + in - '0', in = getchar();
	x *= k;
}

typedef long long ll;

const ll MOD = 1e9 + 7;
const int N = 5e5 + 5;

int n, m;
ll g[N], hash[N], pow[N];// g记录最小质因子，pow存进制的整数次幂
char s[N];
bool vis[N];
vector<ll> pri;

// 线性筛
inline void euler() {
	for (ll i = 2; i <= n; ++i) {
		if (!vis[i])
			pri.push_back(i), g[i] = i;
		for (int j = 0; j < pri.size() && pri[j] * i <= n; ++j) {
			vis[pri[j]*i] = true, g[pri[j]*i] = pri[j];
			if (i % pri[j] == 0)
				break;
		}
	}
}

// 提取hash值
inline ll calc(int l, int r) {
	return ((hash[r] - hash[l-1] * pow[r-l+1]) % MOD + MOD) % MOD;
}

int main() {
	read(n);
	euler();
	scanf("%s", s+1);
    // hash
	for (int i = 1; i <= n; ++i)
		hash[i] = (hash[i-1] * 29 + s[i] - 'a' + 1) % MOD;
	
    // 预处理整数次幂
	pow[0] = 1;
	for (int i = 1; i <= n; ++i)
		pow[i] = (pow[i-1] * 29) % MOD;
    /*
	read(m);
	while (m--) {
		int l, r, len, ans;
		read(l), read(r), ans = len = r - l + 1;
        // 一点点常数优化
		if (calc(l+1, r) == calc(l, r-1)) {
			puts("1");
			continue;
		}
        // 重点
		while (len > 1) {
			if (calc(l+ans/g[len], r) == calc(l, r-ans/g[len]))// 判断
				ans /= g[len];// 除掉循环次数的因子
			len /= g[len];//分解
		}
		printf("%d\n", ans);
	}*/
    for (int i=0;i<=n;i++){
        printf("%d ",g[i]);
    }putchar('\n');
    return 0;
}