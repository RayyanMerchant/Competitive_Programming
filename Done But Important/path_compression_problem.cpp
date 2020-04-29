/*
Problem : https://codeforces.com/problemset/problem/1154/E
DSU path compression idea to remove in between items that go away after
each turn.
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
const int inf = (int) 2e18;

const int maxn = 2e5 + 10;
int n, k;
int a[maxn], lft[maxn], rht[maxn], pos[maxn], ans[maxn];

int lftroot(int i)
{
	return (pos[lft[i]] != -1) ? lft[i] : lft[i] = lftroot(lft[i]);
}

int rhtroot(int i)
{
	return (pos[rht[i]] != -1) ? rht[i] : rht[i] = rhtroot(rht[i]);
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(9);
	#ifdef LOCAL_DEFINE
		freopen("in.txt", "rt", stdin);
	#endif
	
	
	cin >> n >> k;
	set<pii, greater<pii>> st;
	for(int i = 1; i <= n; ++ i)
	{
		cin >> a[i];
		st.insert({a[i], i});
		lft[i] = i - 1;
		rht[i] = i + 1;
	}
	int turn = 0;
	while(st.size() > 0)
	{
		debug(st);
		int team = (turn & 1) ? 2 : 1;
		pii cur = *st.begin();
		st.erase(st.begin());
		int ind = cur.second;
		vector<int> tmp;
		tmp.push_back(ind);
		int till = k;
		int now = ind;
		debug(ind);
		for(int i = 1; i <= k; ++ i)
		{
			int nxt = lftroot(now);
			if(nxt == 0) break;
			tmp.push_back(nxt);
			now = nxt;
		}
		debug(tmp);
		now = ind;
		for(int i = 1; i <= k; ++ i)
		{
			int nxt = rhtroot(now);
			if(nxt == n + 1) break;
			tmp.push_back(nxt);
			now = nxt;
		}
		debug(tmp);
		for(int v : tmp)
		{
			pos[v] = -1;
			ans[v] = team;
			st.erase({a[v], v});
		}
		++ turn;
	}
	
	for(int i = 1; i <= n; ++ i)
		cout << ans[i];
	cout << '\n';
	
	return 0;
}




