


/*
Problem : https://codeforces.com/contest/1230/problem/C

*/


#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cerr << #x " = " << (x) << endl;
#define P(x) cerr << #x << endl;    
#define int long long
typedef pair<int, int> pii;
const int mod = 1000000007;

const int maxn = 10;
int n, m;
vector<vector<int>> adj(maxn);
int vis[maxn][maxn];
int ans;
const int lim = 6;
vector<int> arr(10, 0);

void dfs(int i)
{
    if(i == n + 1)
    {
        memset(vis, 0, sizeof(vis));
        int cnt = 0;
        for(int k = 1; k <= n; ++ k)
        {
            for(int u : adj[k])
            {
                if(!vis[arr[u]][arr[k]] && !vis[arr[k]][arr[u]])
                {
                    vis[arr[u]][arr[k]] = 1;
                    vis[arr[k]][arr[u]] = 1;
                    ++ cnt;
                }
            }
        }
        ans = max(ans, cnt);
        return;
    }
    
    for(int jj = 1; jj <= lim; ++ jj)
    {
        arr[i] = jj;
        dfs(i + 1);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(9);
    
    cin >> n >> m;
    
    for(int i = 0; i < m; ++ i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        
    }
     
    dfs(1);
    cout << ans << endl;
    
    return 0;
}




