#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cerr << #x " = " << (x) << endl;
#define P(x) cerr << #x << endl;    
typedef long long ll;
#define int long long
const int mod = 1000000007;


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(9);
    
    
    vector<char> sieve(1e6  + 100, true);
    sieve[0] = sieve[1] = false;
    
    for(int i = 2; i * i <= 1e6; ++ i)
    {
        if(sieve[i])
        {
            for(int j = i * i; j <= 1e6; j += i)
            {
                sieve[j] = false;
            }
        }
    }
    vector<int> vec;
    for(int i = 2; i <= 1e6; ++ i)
    {
        if(sieve[i])
        vec.push_back(i);
    }
    
    vector<int> pre;
    pre.push_back(vec[0]);
    
    for(int i = 1; i < vec.size(); ++ i)
    {
        pre.push_back(pre[i - 1] + vec[i]);
    }
    
    int t;
    cin >> t;
    while(t --)
    {
        int n;
        cin >> n;
        int index = upper_bound(vec.begin(), vec.end(), n) - vec.begin();
        cout << (index & 1 ? "Alice" : "Bob") << endl;
        
    }
    
    return 0;
}




