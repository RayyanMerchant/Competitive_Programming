#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cerr << #x " = " << (x) << endl;
#define P(x) cerr << #x << endl;    
#define int long long
typedef pair<int, int> pii;
const int mod = 1000000007;

const int maxn = 1000;
int arr[maxn];
int n = 6;
const int lim = 8;

void comb(int i = 1)
{
    if(i == n + 1)
    {
        /* done stop recursion for this end and
         and do what you want with the pattern
         */
        for(int k = 1; k <= n; ++ k)
        {
            cout << arr[k] << " ";
        }
        cout << endl;
        return;
    }
    
    for(int j = 1; j <= lim; ++ j)
    {
        arr[i] = j;
        comb(i + 1);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(9);
    
    comb();
    
    
    return 0;
}




