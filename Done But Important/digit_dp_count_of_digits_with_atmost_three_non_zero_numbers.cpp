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
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
typedef pair<int, int> pii;
const int mod = (int) 1000000007; // 998244353;
const int inf = (int) 2e18;

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




