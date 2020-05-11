








---------------------------------------------------------------------------------------------

subsequence check

bool issubseq(string s, string t)
{
	// check if s is a subsequence of t
	int ps = 0, pt = 0;
	while(ps < s.size() && pt < t.size())
	{
		if(s[ps] == t[pt])
		{
			++ ps; ++ pt;
		}
		else
		{
			++ pt;
		}
	}
	return ps == s.size();
}




---------------------------------------------------------------------------------------------

longest suffix equal to prefix

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

string func(string s)
{
	string og = s;
	int n = s.size();
	s += "#" + s;
	vector<int> z = z_function(s);
	int mx = 0;
	for(int i = n + 2; i < z.size(); ++ i)
	{
		if(i + z[i] == (int) z.size())
		{
			mx = max(z[i], mx);
		}
	}
	return og.substr(0 + mx);
}




---------------------------------------------------------------------------------------------


Longest prefix palindrome for suffix reverse and input into the function


vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

string prefpalin(string s)
{
	string rev = s;
	reverse(rev.begin(), rev.end());
	string is = s + "#" + rev;
	vector<int> z = z_function(is);
	int n = s.size();
	int mx = -1;
	// debug(is[n + 1]);
	// debug(is);
	for(int i = n + 1; i < z.size(); ++ i)
	{
		if(i + z[i] == (int) z.size())
			mx = max(mx, z[i]);
	}
	return s.substr(0, mx);
}



---------------------------------------------------------------------------------------------
Tells you the number of elements within the interval int the given array (with duplicates)
Number of elements in the array in the given range, interval etc
with duplicates.


Problem : https://codeforces.com/problemset/problem/1111/C
Resource : https://www.geeksforgeeks.org/queries-counts-array-elements-values-given-range/

Tells you the number of elements within the interval int the given array (with duplicates)
Input :
	for(int i = 0; i < k; ++ i)
	{
		int tmp;
		cin >> tmp;
		++ mp[tmp];
	}
	for(auto &it : mp)
	{
		arr.push_back(it.first);
		pre.push_back(it.second);
	}
	
	for(int i = 1; i < (int)pre.size(); ++ i)
	{
		pre[i] += pre[i - 1];
	}
Fucntion which returns the number of elements of the array within the range
	int none(int l, int r)
	{
		int ind1 = lower_bound(arr.begin(), arr.end(), l) - arr.begin();
		int ind2 = upper_bound(arr.begin(), arr.end(), r) - arr.begin() - 1;
		int val = ind2 - ind1 + 1;
		// debug(ind2);
		// debug(ind1);
		if(val <= 0)
			return 0;
		if(ind1 == 0)
			return pre[ind2];
		return pre[ind2] - pre[ind1 - 1];
	}


---------------------------------------------------------------------------------------------

Farthest vertex and distance from source in a tree 
Can be modified with visited array for general graphs.
Answer in the form of pair : {distance, vertex _number}

pair<int, int> dfs(int v, int par = -1, int dist = 0) 
{
	p[v] = par;
	pair<int, int> res = make_pair(dist, v);
	for (auto to : g[v]) 
	{
		if (to == par) continue;
		res = max(res, dfs(to, v, dist + 1));
	}
	return res;
}


Function call : dfs(source);

---------------------------------------------------------------------------------------------

Divisor Sieve find the number of divisors 


for(int i = 1; i < maxn; ++ i)
	for(int j = i; j < maxn; j += i)
		++ divisor[j];



---------------------------------------------------------------------------------------------

64 bit random number between l and r

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

---------------------------------------------------------------------------------------------


Fast power, fast pow, fast exponentiation non modular


int mypow(int x, int y) 
{ 
    int res = 1;       
	while (y > 0) 
    { 
        if (y & 1) 
            res = (res * x); 
		y = y >> 1;
        x = (x * x);   
    } 
    return res; 
} 


---------------------------------------------------------------------------------------------

Returns vector of all the divisors of the number
vector<int> get_divisor(int n)
{
	vector<int> ans;
	for(int i = 1; i * i <= n; ++ i)
	{
		if(n % i == 0)
		{
			ans.push_back(i);
			if(n / i != i)
				ans.push_back(n / i);
		}
	}
	sort(all(ans));
	return ans;
}
---------------------------------------------------------------------------------------------


is_prime isprime prime function

bool is_prime(int n)
{
	if(n <= 1) return false;
	for(int i = 2; i * i <= n; ++ i)
		if(n % i == 0)
			return false;
	return true;
}



Returns vector of all the prime factors of a number

vector<int> get_prime(int n)
{
	vector<int> prime;
	for(int i = 2; i * i <= n; ++ i)
	{
		if(n % i == 0) prime.push_back(i);
		while(n % i == 0)
		{
			n /= i;
		}
		
	}
	if(n != 1)prime.push_back(n);
	return prime;
}

power of prime factors / number of them / cnt of them


vector<pii> get_prime(int n)
{
	vector<pii> prime;
	for(int i = 2; i * i <= n; ++ i)
	{
		if(n % i == 0) prime.push_back({i, 0});
		while(n % i == 0)
		{
			n /= i;
			++ prime.back().second;
		}
		
	}
	if(n != 1)prime.push_back({n, 1});
	return prime;
}


using sieve O(n) precomputation and then logn factorization
very fast but requires max range of input variable to be the order of 10 ^ 7


const int maxn = 1e5;
int spf[maxn + 1];
void precompute()
{
	for (int i = 2; i <= maxn; i++) 
	{
		if (!spf[i]) 
		{
			spf[i] = i;
			for (int j = i + i; j <= maxn; j += i)
			{
				if(!spf[j])
					spf[j] = i;
			}
		}
	}
}

vector<pii> get_prime(int n)
{
	vector<pii> prime;
	while(n != 1)
	{
		int cur = spf[n];
		int cnt = 0;
		while(spf[n] == cur)
		{
			n /= spf[n];
			++ cnt;
		}
		prime.emplace_back(cur, cnt);
	}
	return prime;
}

---------------------------------------------------------------------------------------------

local define read from input file

https://codeforces.com/blog/entry/50312

Display time taken to execute by the program :

#ifdef LOCAL_DEFINE
    cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif


---------------------------------------------------------------------------------------------




Binary string with / without leading zeroes to integer value :
int get(string s)
{
	reverse(s.begin(), s.end());
	int is = 1;
	int ans = 0;
	for(int i = 0; i < s.length(); ++ i)
	{
		ans += is * (s[i] - '0');
		is *= 2;
	}
	return ans;
}




---------------------------------------------------------------------------------------------


Finding how many intervals intersect : 
interval / segment intersection / union using stack and sorting based on (value, 0LL) and (val, 1LL) 


https://stackoverflow.com/questions/4542892/possible-interview-question-how-to-find-all-overlapping-intervals




---------------------------------------------------------------------------------------------

returns true if intersects and false if it doesn't intersect


bool check(pii one, pii two) 
{
	int x1 = one.first;
	int y1 = one.second;
	int x2 = two.first;
	int y2 = two.second;
	bool t1 = max(x1, x2) > min(y1, y2);
	bool t2 = min(y1, y2) < max(x1, x2);
	// cout << "t1 = " << t1 << '\n';
	// cout << "t2 = " << t2 << '\n';
	bool wont = t2 || t1;
	if(wont) return false;
	return true;
}



---------------------------------------------------------------------------------------------

Binary string to decimal
binary to decimal

int get(string s)
{
	reverse(s.begin(), s.end());
	int place = 1;
	int cur = 0;
	for(int i = 0; i < s.length(); ++ i)
	{
		cur += place * (s[i] - '0');
		place *= 2;
	}
	return cur;
}








integer ceil without function : 

ceil(a / b) = (a + b - 1) / b

int myceil(int a, int b)
{
	return (a + b - 1) / b;
}


---------------------------------------------------------------------------------------------


keywords : python input intput python how to take input in python

Python Input :-

1. Just one value : a = int(input())

2. Two or three consecutive values : m,n=map(int,input().split()) 

3. Array as a space separated line :  ar=list(map(int,input().split()))

list comprehension for space separated line
nums = [int(x) for x in input().split()]


---------------------------------------------------------------------------------------------

int add(int a, int b) 
{
	a += b;
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
	return a;
}

int mul(int a, int b) 
{
	return a * 1ll * b % MOD;
}
---------------------------------------------------------------------------------------------

Problem : https://codeforces.com/contest/1200/problem/C
To avoid precision errors when rounding up instead of doing a = (double) x / y
a = (x - 1) / y solves all precision problems 

---------------------------------------------------------------------------------------------

how to take a space seperated integers in a line when you don't know the number of elements
in the line you use getline to take the string along with the spaces and then use string stream
to partition it along spaces like cin and take input from it in a variable


	const int maxn = 1e6;
    string s;
    getline(cin, s);
    stringstream stream(s);
    int x;
    //vector<int> a(maxn);
    vector<int> freq(maxn, 0);
    //int d = 0;
    while (stream >> x) 
    {
        //a[d++] = x;
        freq[x]++;
    }
    //int n = d;
	
---------------------------------------------------------------------------------------------

when using getline with multiple test cases first take the input as t and before while(t--)
	just do a summy getline otherwise it won't work.



int t;
    cin >> t;
    string xyz;
    getline(cin, xyz);
    while(t--)




---------------------------------------------------------------------------------------------



For problems where you get this :

Output a single real number corresponding to the probability. The answer will be considered correct if its relative or absolute error doesn't exceed 10^-9.	

OR

The answer will be considered correct if its absolute or relative error doesn't exceed 10^-9

Do this : 

cout << fixed << setprecision(9) << ans << endl;	

	
---------------------------------------------------------------------------------------------

Codeforces big int c++ library:
https://codeforces.com/blog/entry/22566
Direct Link : 


Modified version : https://codeforces.com/blog/entry/67827
Direct Link : https://pastebin.com/h0brWB2T



---------------------------------------------------------------------------------------------

Always check constraints to make sure if int is enough if you get a WA try #define int long long maybe its an overflow error.
So always check contraints especially when you require a sum.

	
---------------------------------------------------------------------------------------------

Reverse an adjacency list	
	
	Create a new adjacency list and add all edges in reverse order.

List oldAL[]; // old adjacency list
List newAL[]; // new adjacency list
 
for (int u = 0; u < nV; u++) // for each vertex u 
    for (int v : oldAL[u])  // for each adj vertex add u to its new Adjacency List
        newAL[v].add(u); // v -> u = reverse(u -> v)
4.7k views · View 8 Upvoters
	
	
---------------------------------------------------------------------------------------------
	
To get the assign size of each vertex in a connected component.

#include<bits/stdc++.h>
using namespace std;

const int N = 1000043;
vector<int> g[N];

int color[N];
int siz[N];
int n, m;
int cc = 0;

int dfs(int x)
{
	if(color[x])
		return 0;
	color[x] = cc;
	int ans = (x < n ? 1 : 0);
	for(auto y : g[x])
		ans += dfs(y);
	return ans; 
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		int k;
		scanf("%d", &k);
		for(int j = 0; j < k; j++)
		{
			int x;
			scanf("%d", &x);
			--x;
			g[x].push_back(i + n);
			g[i + n].push_back(x);
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(!color[i])
		{
			cc++;
			siz[cc] = dfs(i);
		}
		printf("%d ", siz[color[i]]);
	}
}
	
	
	
	
	
	
---------------------------------------------------------------------------------------------

global vector : vector<vector<int>> g;
	
to reinitialise inside main whenver thos while(t--) problems are given for test cases
use : g = vector<vector<int>>(n); 
best and easiest way to reintialise or clear a vector	
	
	
	
---------------------------------------------------------------------------------------------

Remove duplicates from a string :


Just using vector, sort + unique
sort( vec.begin(), vec.end() );
vec.erase( unique( vec.begin(), vec.end() ), vec.end() );


Convert to set (manually)
set<int> s;
unsigned size = vec.size();
for( unsigned i = 0; i < size; ++i ) s.insert( vec[i] );
vec.assign( s.begin(), s.end() );



Convert to set (using a constructor)
set<int> s( vec.begin(), vec.end() );
vec.assign( s.begin(), s.end() );
	


---------------------------------------------------------------------------------------------
bool operator<(team other) const
   {
     if(points < other.points)
       {
          return true;
       }
     else if(points > other.points)
     {
        return false;
      }
     else
     {
        if(diff <= other.diff)
        {
          return true;
        }
       else
       {
        return false;
       }
     }
   }	
	
	



---------------------------------------------------------------------------------------------
	
segment tree range maxnimum query this page along with the cp - algorithms page on segment trees.	

https://github.com/amulyagaur/Segment-Tree/blob/master/range-max-query.cpp




---------------------------------------------------------------------------------------------

Problem : https://codeforces.com/problemset/problem/478/B
Name : Random Teams


Combinatorics logic of how to get pairs when n is given and also how divide a non divisoble number like 10 into pairs of 3 evenly like 3, 3, 4. look at minans for that.

So for min divide them into pairs of equals like 9 in 3 would be 3, 3, 3 and 10 in 3 would be 3, 3, 4
Implementing min is hard first if it 10 split 9 to get 3, 3, 3 and then distribute the remaining to n % m components which here is 10 % 3 = 1 so 3, 3, 3 becomes 3, 3, 4 after distributing the extra one.


For max put one in all m - 1 and remaining that is n - (m - 1) in one team so for 10 in 3 it would be 1, 1, 8 

int get_pairs(int n)
{
    int ans = (n * (n - 1)) / 2;
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    int n, m;
    cin >> n >> m;
    
    int maxans = get_pairs(n - m + 1);
    int minans;
    
    int each = (n - n % m) / m;
    // m teams and n % m get an extra member
    int ans1 = get_pairs(each + 1) * (n % m);
    int ans2 = get_pairs(each) * (m - n % m);
    minans = ans1 + ans2;
    
    cout << minans << " " << maxans << endl;
    
    return 0;
}	
	



---------------------------------------------------------------------------------------------
	
import bisect
 
a = []

th = bisect.bisect_left(a, k)


use bisect like this where bisect left is lower_bound and bisect right is upper_bound
a is the list / vector ans k is the element whoose lower bound we are looking for.	



---------------------------------------------------------------------------------------------
	
number of digits till an i digit number is calculated and stored in b and then the prefix sum is taken in a so a[i] tells you the sum of number of digits till all i digit numbers. Very useful technique used to solve these problems :-
1. Digits Sequence (Hard Edition) - https://codeforces.com/contest/1177/problem/B
2. Vanya and Books - https://codeforces.com/contest/552/problem/B	
    
b = []
a = []
b.append(0)

for i in range(1, 15):
	b.append(9 * i * (10 ** (i - 1)))


a.append(b[0])
for i in range(1, 15):
	a.append(a[i - 1] + b[i])	



---------------------------------------------------------------------------------------------
	
	







	
	
	