#include <bits/stdc++.h>
using namespace std;

/*
Problem : https://codeforces.com/problemset/problem/923/C
Solution : https://codeforces.com/contest/923/submission/80628601
Here we also delete an element from a 2d trie by maintaing a separate
frequency array for each node and only if frequency of that node is more than zero do we actually then use it in our answer.

Here the frequency of a trie is given by the ++ cl number assigned to it during insertion.
*/
   
#define int long long
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
typedef pair<int, int> pii;
const int mod = (int) 1000000007; // 998244353;
const int inf = (int) 2e18;

const int maxn = 1e7;
int c[maxn][2];
int cnt[maxn];
int cl;

void ins(int num)
{
	int v = 0;
	for(int i = 30; i >= 0; -- i)
	{
		int bit = (num >> i) & 1;
		if(!c[v][bit])
		{
			c[v][bit] = ++ cl;
		}	
		++ cnt[c[v][bit]];
		v = c[v][bit];
	}
}

void del(int num)
{
	int v = 0;
	for(int i = 30; i >= 0; -- i)
	{
		int bit = (num >> i) & 1;
		-- cnt[c[v][bit]];
		v = c[v][bit];
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
	
	
	int n;
	cin >> n;
	vector<int> a(n), p(n);
	for(int i = 0; i < n; ++ i)
		cin >> a[i];
	for(int i = 0; i < n; ++ i)
	{
		cin >> p[i];
		ins(p[i]);
	}
	
	for(int x : a)
	{
		int su = 0;
		int v = 0;
		int use = 0;
		for(int i = 30; i >= 0; -- i)
		{
			int bit = (x >> i) & 1;
			if(c[v][bit] && cnt[c[v][bit]] > 0)
			{
				v = c[v][bit];
				use += bit * (1ll << i);
			}
			else
			{
				use += !bit * (1ll << i);
				su += (1ll << i);
				v = c[v][!bit];
			}
		}
		cout << su << " ";
		del(use);
	}
	
	cout << '\n';
	
	return 0;
}




