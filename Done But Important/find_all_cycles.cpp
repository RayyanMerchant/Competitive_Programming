/*
Problem : https://codeforces.com/contest/1027/problem/D
Reference : https://cp-algorithms.com/graph/finding-cycle.html
Find and enumerate all cycles done in code below
Find min value in all cycles
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
const int mod = (int) 1000000007;

const int maxn = 2e5 + 10;
const int inf = 1e16;
vector<int> adj[maxn];
int a[maxn], c[maxn], col[maxn], par[maxn];
vector<int> cycle_start, cycle_end;

void dfs(int v)
{
	col[v] = 1;
	for(int u : adj[v])
	{
		if(col[u] == 0)
		{
			par[u] = v;
			dfs(u);
		}
		else if(col[u] == 1)
		{
			cycle_end.push_back(v);
			cycle_start.push_back(u);
		}
	}
	col[v] = 2;
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
	for(int i = 1; i <= n; ++ i)
	{
		cin >> c[i];
	}
	for(int i = 1; i <= n; ++ i)
	{
		cin >> a[i];
		adj[i].push_back(a[i]);
	}
	
	for(int i = 1; i <= n; ++ i)
	{
		if(col[i]) continue;
		dfs(i);
	}
	int ans = 0;
	for(int i = 0; i < cycle_start.size(); ++ i)
	{
		int mn = c[cycle_start[i]];
		vector<int> cur;
		for(int j = cycle_end[i]; j != cycle_start[i]; j = par[j])
		{
			mn = min(mn, c[j]);
			cur.push_back(j);
		}
		cur.push_back(cycle_start[i]);
		debug(cur);
		ans += mn;
	}
	
	cout << ans << '\n';
	
	return 0;
}




