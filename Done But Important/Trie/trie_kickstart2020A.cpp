/*
Problem : bundling kicstart round A 2020
Trie 2D implementation reference:
https://paste.ubuntu.com/8183185/

*/
#include <bits/stdc++.h>
using namespace std;
   
#define int long long
typedef pair<int, int> pii;
const int mod = (int) 1000000007; // 998244353;

int n, k;
const int maxn = 2e6 + 20;
int c[maxn][30];
int en[maxn];
int ans;

int dfs(int v, int depth)
{
	int till = en[v];
	for(int i = 0; i < 26; ++ i)
	{
		if(c[v][i] != 0)
		{
			till += dfs(c[v][i], depth + 1);
		}
	}
	int lft = till % k;
	int num = (till - lft) / k;
	ans += num * depth;
	
	return lft;
}

void test_case()
{
	cin >> n >> k;
	int sz = 0;
	for(int i = 0; i < n; ++ i)
	{
		string s;
		cin >> s;
		int v = 0;
		for(char& tmp : s)
		{
			int ch = tmp - 'A';
			if(c[v][ch] == 0)
			{
				c[v][ch] = ++ sz;
			}
			v = c[v][ch];
		}
		++ en[v];
	}
	ans = 0;
	int is = dfs(0, 0);
	cout << ans << '\n';
	for(int i = 0; i <= sz + 10; ++ i)
	{
		en[i] = 0;
		for(int j = 0;  j < 30; ++ j)
		{
			c[i][j] = 0;
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(9);
	#ifdef LOCAL_DEFINE
		freopen("in.txt", "rt", stdin);
	#endif
	
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++ i)
	{
		cout << "Case #" << i << ": ";
		test_case();
	}
	
	return 0;
}




