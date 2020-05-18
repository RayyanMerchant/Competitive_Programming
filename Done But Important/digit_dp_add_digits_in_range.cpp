/*
Link : https://www.hackerrank.com/contests/code-uncode-round-1/challenges/winning-the-lottery/problem
*/
#include <bits/stdc++.h>
using namespace std;

int dp[20][200][5];
vector<int> num;

int solve(int ind, int sum, int edge)
{
	if(ind == (int) num.size())
		return sum;
	if(dp[ind][sum][edge] != -1)
		return dp[ind][sum][edge];
	int lim = -1;
	if(edge)
		lim = num[ind];
	else
		lim = 9;
	int res = 0;
	for(int i = 0; i <= lim; ++ i)
	{
		int new_edge = 0;
		if(edge && i == lim)
			new_edge = 1;
		res += solve(ind + 1, sum + i, new_edge);
	}
	return dp[ind][sum][edge] = res;
}

int func(int a)
{
	num.clear();
	while(a)
	{
		num.push_back(a % 10);
		a /= 10;
	}
	reverse(num.begin(), num.end());
	memset(dp, -1, sizeof(dp));
	return solve(0, 0, 1);
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(9);
	#ifdef LOCAL_DEFINE
		freopen("in.txt", "rt", stdin);
	#endif
	
	
	int a, b;
	cin >> a >> b;
	int fir = func(a - 1) % mod;
	int sec = func(b) % mod;
	cout << (sec - fir + mod) % mod << '\n';
	
	return 0;
}




