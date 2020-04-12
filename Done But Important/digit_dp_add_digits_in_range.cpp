/*
Link : https://www.hackerrank.com/contests/code-uncode-round-1/challenges/winning-the-lottery/problem
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
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef LOCAL_DEFINE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
   
#define int long long
typedef pair<int, int> pii;
const int mod = (int) 1e6;

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




