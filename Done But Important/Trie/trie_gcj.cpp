/*
Problem : alien rhyme gcj 2019 round 1A
Trie 2D implementation reference:
https://paste.ubuntu.com/8183185/

*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pii;
const int mod = (int) 1000000007; // 998244353;

vector<int> done;
vector<string> inpt;
const int maxn = 50 * 1000 + 10;
int c[maxn][30];
int en[maxn];
int ans;

void prin(int sz)
{
	for(int i = 0; i <= sz; ++ i)
	{
		for(int j = 0; j < 26; ++ j)
		{
			cout << c[i][j] << " ";
		}
		cout << '\n';
	}
	for(int i = 0; i <= sz; ++ i)
	{
		cout << en[i] << " ";
	}
	cout << '\n';
}

int dfs(int v)
{
	int till = en[v]; // 1 if it is an end of a word
	for(int i = 0; i < 26; ++ i)
	{
		if(c[v][i] != 0)
		{
			till += dfs(c[v][i]);
		}
	}
	if(till >= 2 && v != 0)
	{
		ans += 2;
		till -= 2;
	}
	return till;
}

void test_case()
{
	int n;
	cin >> n;
	done.assign(n + 1, 0);
	inpt.resize(n);
	for(int i = 0; i < n; ++ i)
	{
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		inpt[i] = s;
	}
	sort(inpt.begin(), inpt.end(), [](string& fir, string& sec) -> bool
	{
		return fir.size() > sec.size();
	});
	// debug(inpt);
	int sz = 0;
	
	for(string& s : inpt)
	{
		int v = 0;
		// debug(s);
		for(char& ch : s)
		{
			int alph = ch - 'A';
			if(c[v][alph] == 0)
			{
				c[v][alph] = ++ sz;
			}
			v = c[v][alph];
			// debug(v);
		}
		++ en[v];
	}
	
	// prin(sz);
	
	ans = 0;
	
	int is = dfs(0);
	
	cout << ans << '\n';
	
	for(int i = 0; i <= sz + 10; ++ i)
	{
		en[i] = 0;
		for(int j = 0; j < 30; ++ j)
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




