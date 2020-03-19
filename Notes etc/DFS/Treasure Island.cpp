


/*
D. Treasure Island
https://codeforces.com/contest/1214/problem/D
*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define debug(x) cerr << #x " = " << (x) << endl;
#define P(x) cerr << #x << endl;    
typedef long long ll;
//#define int long long
const int mod = 1000000007;

int n, m;

bool isv(int i, int j, vector<vector<int>> &a, vector<vector<int>> &vis)
{
    return i >= 1 && i <= n && j >= 1 && j <= m && a[i][j] == 1 && vis[i][j] == 0 && vis[n][m] == 0;
}

void dfs(int i, int j, vector<vector<int>> &a, vector<vector<int>> &vis)
{
    vis[i][j] = 1;
    
    if(isv(i + 1, j, a, vis))
        dfs(i + 1, j, a, vis);
    if(isv(i, j + 1, a, vis))
        dfs(i, j + 1, a, vis);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(9);
    
    
    
    cin >> n >> m;
    int n1 = n + 10, m1 = m  + 10;
    vector<vector<int>> a(n1, vector<int>(m1));
    vector<vector<int>> vis(n1, vector<int>(m1));
    
    
    for(int i = 1; i <= n; ++ i)
    {
        string s;
        cin >> s;
        for(int j = 1; j <= m; ++ j)
        {
            int k = j - 1;
            vis[i][j] = 0;
            if(s[k] == '.') a[i][j] = 1;
            else a[i][j] = -1;
        }
    }
    
    dfs(1, 1, a, vis);
    if(vis[n][m] == 0)
    {
        cout << "0" << endl;
    }
    else
    {
        vis[n][m] = 0;
        vis[1][1] = 0;
        
        dfs(1, 1, a, vis);
        if(vis[n][m] == 0)
            cout << "1" << endl;
        else
            cout << "2" << endl;
    }
    
    return 0;
}




