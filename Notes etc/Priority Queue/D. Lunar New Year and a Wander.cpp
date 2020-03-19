
/*
D. Lunar New Year and a Wander
https://codeforces.com/contest/1106/problem/D
*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cerr << #x " = " << (x) << endl;
#define P(x) cerr << #x << endl;    
typedef long long ll;
//#define int long long
const int mod = 1000000007;


struct cmp
{
    bool operator()(int const &p1, int const &p2)
    {
        return p1 > p2;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(9);
    
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> vis(n, 0);
    for(int i = 0; i < m; ++ i)
    {
        int u, v;
        cin >> u >> v;
        -- u; -- v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    priority_queue<int, vector<int>, cmp> q;
    q.push(0);
    vis[0] = 1;
    vector<int> ans;
    while(!q.empty())
    {
        int cur = q.top();
        q.pop();
        ans.push_back(cur + 1);
        for(int u : adj[cur])
        {
            if(vis[u] == 0)
            {
                vis[u] = 1;
                q.push(u);
            }
        }
    }
    
    for(int i = 0; i < ans.size(); ++ i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}




