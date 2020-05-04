/*
Problem : https://codeforces.com/problemset/problem/1042/D
Editorial : https://codeforces.com/blog/entry/61891 has fenwick tree order statistics
using pair to get multiset oset is a trick given in the github link
Here I changes less<T> to greater<T> because I wanted a value strictly greater than and used 
infinity in the size to make sure that {2, 0} didn't get included so it is like 
searchong for {2, 10^18} it will never return any instance of 2 it will only count the number
of elements greater than 2 i.e : 3.
*/

/*
https://codeforces.com/blog/entry/11080
https://stackoverflow.com/questions/44238144/order-statistics-tree-using-gnu-pbds-for-multiset
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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
template <typename T>
using oset =
    tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(9);
    
	int n, t;
	cin >> n >> t;
	vector<int> a(n + 1, 0), pre(n + 1, 0);
	for(int i = 1; i <= n; ++ i)
		cin >> a[i];
	for(int i = 1; i <= n; ++ i)
		pre[i] = pre[i - 1] + a[i];
	
	oset<pii> st;
    int sz = 0;
	
	st.insert({0, ++ sz});
	int ans = 0;
	for(int i = 1; i <= n; ++ i)
	{
		int want = pre[i] - t;
		int cnt = st.order_of_key({want, inf});
		ans += cnt;
		st.insert({pre[i], ++ sz});
	}
	
	cout << ans << '\n';
    
    return 0;
}











