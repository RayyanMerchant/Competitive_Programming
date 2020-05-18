

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pii;
const int mod = (int) 1000000007; // 998244353;
const int inf = (int) 2e18;
 
const int maxn = 3e6;
int c[maxn][3];
int en[maxn];
int sz;
 
int dfs(int v, int d)
{
	debug(v, d);
	if(c[v][0] == -1 && c[v][1] == -1)
		return 0;
	if(c[v][0] == -1)
		return dfs(c[v][1], d - 1);
	if(c[v][1] == -1)
		return dfs(c[v][0], d - 1);
	return (1LL << d) + min(dfs(c[v][0], d - 1), dfs(c[v][1], d - 1));
}
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(9);
	#ifdef LOCAL_DEFINE
		freopen("in.txt", "rt", stdin);
	#endif
	
	int n;
	cin >> n;
	memset(c, -1, sizeof(c));
	for(int i = 0; i < n; ++ i)
	{
		int tmp;
		cin >> tmp;
		int v = 0;
		for(int i = 30; i >= 0; -- i)
		{
			int bit = (tmp >> i) & 1;
			if(c[v][bit] == -1)
			{
				c[v][bit] = ++ sz;
			}
			v = c[v][bit];
		}
		++ en[v];
	}
	
	int ans = dfs(0, 30);
	cout << ans << '\n';
	
	return 0;
}
 
 