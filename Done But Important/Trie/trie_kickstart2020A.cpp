/*
Problem : bundling kicstart round A 2020
Trie 2D implementation reference:
https://paste.ubuntu.com/8183185/

*/
#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char& ch) {
	string s = "";
	s += ch;
	return "'" + s + "', ";
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
 
void debug_out() { cout << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cout << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef LOCAL_DEFINE
#define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
   
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
	// if(till >= k)
	// {
		// till -= k;
		// debug(depth, v);
		// ans += depth;
	// }
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




