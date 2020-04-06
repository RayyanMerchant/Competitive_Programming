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

int n;
const int maxn = 4e5;
vector<int> done(maxn, -1);
vector<int> a;


const int inf = 1e17;
struct node
{
	int mx, mn, mnid, mxid;
};
node t[4 * maxn];
void update(int v, int tl, int tr, int pos, int val)
{
	if(tl == tr)
	{
		t[v].mx = t[v].mn = val;
		t[v].mxid = t[v].mnid = pos;
	}
	else
	{
		int mid = (tl + tr) / 2;
		if(pos <= mid)
			update(2 * v, tl, mid, pos, val);
		else
			update(2 * v + 1, mid + 1, tr, pos, val);
		if(t[2 * v].mn < t[2 * v + 1].mn)
		{
			t[v].mn = t[2 * v].mn; t[v].mnid = t[2 * v].mnid;
		}
		else
		{
			t[v].mn = t[2 * v + 1].mn; t[v].mnid = t[2 * v + 1].mnid;
		}
		if(t[2 * v].mx > t[2 * v + 1].mx)
		{
			t[v].mx = t[2 * v].mx; t[v].mxid = t[2 * v].mxid;
		}
		else
		{
			t[v].mx = t[2 * v + 1].mx; t[v].mxid = t[2 * v + 1].mxid;
		}
	}
}

pii mxq(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return {-inf, -1};
    if (l == tl && r == tr) {
        return {t[v].mx, t[v].mxid};
    }
    int tm = (tl + tr) / 2;
    return max(mxq(v*2, tl, tm, l, min(r, tm))
           , mxq(v*2+1, tm+1, tr, max(l, tm+1), r));
}

pii mnq(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return {+inf, -1};
    if (l == tl && r == tr) {
        return {t[v].mn, t[v].mnid};
    }
    int tm = (tl + tr) / 2;
    return min(mnq(v*2, tl, tm, l, min(r, tm))
           , mnq(v*2+1, tm+1, tr, max(l, tm+1), r));
}



int morethan(int l, int r, int val)
{
	while(l < r)
	{
		int mid = (l + r) / 2;
		// debug(l, r, mid);
		pii qu = mxq(1, 0, n - 1, l, mid);
		// debug(qu);
		if(qu.first > val)
		{
			r = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	return r;
}

int lessthan(int l, int r, int val)
{
	while(l < r)
	{
		int mid = (l + r) / 2;
		debug(l, r, mid);
		pii qu = mnq(1, 0, n - 1, l, mid);
		debug(qu);
		if(qu.first < val)
		{
			r = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	return r;
}

int solve(int i)
{
	if(done[i] != -1)
		return done[i];
	int mor = morethan(i, n - 1, a[i]);
	if(a[mor] <= a[i]) mor = inf;
	int les = lessthan(i, n - 1, (a[i] + 1) / 2);
	debug(i, mor, les, (a[i] + 1) / 2);
	if(les < mor)
	{
		return done[i] = les - i;
	}
	return done[i] = (mor - i) + solve(mor);
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(9);
	#ifdef LOCAL_DEFINE
		freopen("in.txt", "rt", stdin);
	#endif
	
	cin >> n;
	a.resize(n * 3);
	for(int i = 0; i < n; ++ i)
	{
		cin >> a[i];
		a[n + i] = a[i];
		a[n + n + i] = a[i];
		update(1, 0, 3 * n - 1, i, a[i]);
		update(1, 0, 3 * n - 1, n + i, a[n + i]);
		update(1, 0, 3 * n - 1, n + n + i, a[n + n + i]);
	}
	n *= 3;
	debug(a);
	if(*min_element(a.begin(), a.end()) >= (*max_element(a.begin(), a.end()) + 1) / 2)
	{
		for(int i = 0; i < n / 3; ++ i)
		{
			cout << "-1 ";
		}
		cout << '\n';
		return 0;
	}
	debug(n);
	for(int i = 0; i < n / 3; ++ i)
	{
		solve(i);
	}
	for(int i = 0; i < n / 3; ++ i)
	{
		cout << done[i] << " ";
	}
	cout << '\n';
	
	return 0;
}




