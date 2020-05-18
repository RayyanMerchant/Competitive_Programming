/*
Problem : https://codeforces.com/problemset/problem/1036/C
Solution : https://codeforces.com/contest/1036/submission/78434783

In short question : from L to R count of numbers having no more than three non zero digits in their decimal represenatation.

here usual digit dp like sum of digits in range but using an extra 
lft state to make sure that no more than 3 nonzero elements are used
also if lft goes negative then returning 0 value.
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> fig;
int dp[22][5][5];

int solve(int ind, int lft, int edge)
{
	if(lft < 0)
		return 0;
	if(ind == sz(fig))
		return 1;
	if(dp[ind][lft][edge] != -1)
		return dp[ind][lft][edge];
	int lim = -1;
	if(edge)
		lim = fig[ind];
	else 
		lim = 9;
	int res = 0;
	for(int i = 0; i <= lim; ++ i)
	{
		int new_edge = 0;
		if(edge && i == lim)
			new_edge = 1;
		if(i == 0)
			res += solve(ind + 1, lft, new_edge);
		else
			res += solve(ind + 1, lft - 1, new_edge);
	}
	// debug(ind, lft, edge, res);
	return dp[ind][lft][edge] = res;
}

int get(int r)
{
	fig.clear();
	while(r)
	{
		fig.push_back(r % 10);
		r /= 10;
	}
	reverse(all(fig));
	memset(dp, -1, sizeof(dp));
	return solve(0, 3, 1);
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
	while(t --)
	{
		int l, r;
		cin >> l >> r;
		debug(get(r), get(l - 1));
		cout << get(r) - get(l - 1) << '\n';
	}
	
	return 0;
}




