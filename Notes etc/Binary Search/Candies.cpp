
/*

C. Candies
https://codeforces.com/problemset/problem/991/C


*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cerr << #x " = " << (x) << endl;
#define P(x) cerr << #x << endl;    
typedef long long ll;
#define int long long
const int mod = 1000000007;

int n;

int check(int k)
{
    int copy = n;
    int sum = 0;
    while(true)
    {
        if(copy - k > 0)
        {
            copy -= k;
            sum += k;
            
        }
        else
        {
            sum += copy;
            break;
        }
        if(copy >= 10)
        {
            copy -= (copy / 10);
        }
    }
    return sum;
}

int binsearch(int lo, int hi)
{
    int ans = 1e18;
    while(lo <= hi)
    {
        int mid = (lo + hi + 1) / 2;
//        debug(mid);
        int sum = check(mid);
        if(sum >= (n + 1) / 2)
        {
            ans = min(ans, mid);
//            debug(lo);
//            debug(hi);
//            debug(sum);
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
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
    
    int ans = binsearch(1, 1e18);
    
    cout << ans << endl;
    
    return 0;
}




