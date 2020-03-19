
/*
Problem - Fly Div 2C
https://codeforces.com/contest/1010/problem/A
*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cerr << #x " = " << (x) << endl;
#define P(x) cerr << #x << endl;    
typedef long long ll;
#define int double
const int mod = 1000000007;
const int ep = 1e-7;
const int is = 1e9 + 100;
int n;
int m;
vector<int> a(10000);
vector<int> b(10000);
bool check(int fuel)
{
    int cur = fuel + m;
    cur -= (cur / a[0]);
    
    if(cur - m < ep) return false;
    for(int i = 1; i < n; ++ i)
    {
        cur -= (cur / a[i]);
        
        if(cur - m < ep) return false;
        cur -= (cur / b[i]);
        
        if(cur - m < ep) return false;
    }
    cur -= (cur / b[0]) ;
    
    if(cur - m < ep) return false;
    return true;
}

int binsearch(int lo, int hi)
{
    int ans = is;
    while(1e-6 <= hi - lo)
    {
        int mid = (lo + hi) / 2;
//        debug(mid);
//        debug(lo);
//        debug(hi);
//        debug(check(mid));
        if(check(mid))
        {
            hi = mid;
            ans = min(ans, mid);
        }
        else
        {
            lo = mid;
        }
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(9);
    
    
    cin >> n;
    cin >> m;
    for(int i = 0; i < n; ++ i)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; ++ i)
    {
        cin >> b[i];
    }
    int ans = binsearch(1, is);
    if(ans >= is)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
    
    
    return 0;
}




