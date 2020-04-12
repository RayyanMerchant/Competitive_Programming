/*
Problem : https://www.codechef.com/COG2020/problems/COG2004
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

vector<int> fact, invfact, two;

int modpow(int x, int y, int p = mod) 
{ 
	int res = 1;       
	x %= p;   
	while (y > 0) 
	{ 
		if (y & 1) 
			res = (res * x) % p; 
		y >>= 1;
		x = (x * x) % p;   
	} 
	return res; 
} 
int add(int x, int y) 
{
	x += y;
	if (x >= mod) return x - mod;
	return x;
}
int sub(int x, int y) 
{
	x -= y;
	if (x < 0) return x + mod;
	return x;
}
int inv(int a, int m = mod)
{
	return modpow(a, m - 2, m);
}
int mul(int a, int b) 
{
	return (long long) a * b % mod;
}

void calc_fact(int n)
{
	fact.resize(n);
	invfact.resize(n);
	two.resize(n);
	fact[0] = invfact[0] = two[0] = 1;
	for(int i = 1; i < n; ++ i)
	{
		fact[i] = mul(fact[i - 1], i);
		invfact[i] = inv(fact[i]);
		two[i] = mul(two[i - 1], 2);
	}
}

int ncr(int n, int r)
{
	assert(n >= r && n >= 0 && r >= 0);
	int ans = mul(fact[n], mul(invfact[n - r], invfact[r]));
	return ans;
}


void multiply(int F[2][2], int M[2][2]); 

void temppow(int F[2][2], int res[2][2], int y) 
{ 
	while (y > 0) 
	{ 
		if (y & 1) 
		{
			multiply(res, F);
		}
			
		y >>= 1;
		multiply(F, F);  
	} 
} 
 
/* function that returns nth Fibonacci number */
int fib(int n) 
{ 
  int F[2][2] = {{2,2},{1,0}}; 
  if (n == 0) 
    return 1; 
  int res[2][2] = {{1, 0}, {0, 1}};
  temppow(F, res, n-1);
  debug(res[0][0], res[0][1]);
  debug(res[1][0], res[1][1]);
  int is = add(mul(res[0][0], 2), res[0][1]);
  return is; 
} 

  
void multiply(int F[2][2], int M[2][2]) 
{ 
  int x =  add(mul(F[0][0], M[0][0]), mul(F[0][1], M[1][0])); 
  int y =  add(mul(F[0][0], M[0][1]), mul(F[0][1], M[1][1])); 
  int z =  add(mul(F[1][0], M[0][0]), mul(F[1][1], M[1][0])); 
  int w =  add(mul(F[1][0], M[0][1]), mul(F[1][1], M[1][1])); 
  
  F[0][0] = x; 
  F[0][1] = y; 
  F[1][0] = z; 
  F[1][1] = w; 
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
		int n;
		cin >> n;
		cout << fib(n) << '\n';
	}
	
	return 0;
}




