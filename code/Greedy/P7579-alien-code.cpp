#include <bits/stdc++.h>
using namespace std;
int n;
set<int> ans; /*set 自动从小到大排序*/
char query(int l1, int r1, int l2, int r2) /*查询[l1,r1],[l2,r2] 区间大小关系*/
{
	putchar('1');
	printf(" %d", r1 - l1 + 1), fflush(stdout);
	for (int i = l1; i <= r1; i++) printf(" %d", i), fflush(stdout);
	printf(" %d", r2 - l2 + 1), fflush(stdout);
	for (int i = l2; i <= r2; i++) printf(" %d", i), fflush(stdout);
	putchar('\n'); char c; return cin >> c, c;
}
void answer(){putchar('2');for (auto i : ans) printf(" %d", i);fflush(stdout);exit(0);} /*输出答案*/
void insert(const int &x) {ans.insert(x);if (ans.size() == 2) return answer();} /*插入答案*/
void solve2(int, int, int);
void solve3(int, int, int);
inline void solve2(int l, int r, int k) /*? 显然，没有客观性*/
{
	if (!k) return void();
	if (l == r) return insert(l);
	int length = r - l + 1, mid = (l + r) >> 1, lmid, rmid;
	char x = query(l, lmid = ((length % 2 == 0) ? (l + r - 1) >> 1 : mid - 1), rmid = ((length % 2 == 0) ? (l + r + 1) >> 1 : mid + 1), r);
	if (x == '=')
	{
		if (k == 1) insert(mid);
		solve3(l, lmid, k - 1);
		solve3(rmid, r, k - 1);
		return void();
	}
	if (k == 1)
	{
		solve3(l, lmid, x == '<');
		solve3(rmid, r, x == '>');
	}
	if (k == 2)
	{
		if (length % 2 == 0 || query(mid, mid, mid + (x == '<' ? 1 : -1), mid + (x == '<' ? 1 : -1)) == '=')
			solve2(l, lmid, (x == '<') * 2), solve2(rmid, r, (x == '>') * 2);
		else
			insert(mid), solve3(l, lmid, x == '<'), solve3(rmid, r, x == '>');
	}
}
inline void solve3(int l, int r, int k)
{
	if (!k) return void();
	int length = r - l + 1, size = length / 3, lmid = l + size - 1, rmid = lmid + size;
	if (length <= 2) return solve2(l, r, k);
	char x = query(l, lmid, lmid + 1, rmid);
	if (x == '=') solve3(rmid + 1, r, 1);
	if (x == '>') solve3(lmid + 1, rmid, 1);
	if (x == '<') solve3(l, lmid, 1);
}
signed main()
{
	cin >> n;
	solve2(1, n, 2);
	answer();
	return 0;
}