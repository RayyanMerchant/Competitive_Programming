/*
Problem : https://codeforces.com/problemset/problem/816/B
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int t[4 * maxn], lazy[4 * maxn];
int len = 2e5 + 5;

void push(int v) {
    t[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l <= tl && tr <= r)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return query(v*2, tl, tm, l, min(r, tm)) + 
               query(v*2+1, tm+1, tr, max(l, tm+1), r);
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(9);
	#ifdef LOCAL_DEFINE
		freopen("in.txt", "rt", stdin);
	#endif
	
	int n, k, q;
	cin >> n >> k >> q;
	for(int i = 0; i < n; ++ i)
	{
		int l, r;
		cin >> l >> r;
		update(1, 0, len, l, r, 1);
	}
	for(int i = 0; i <= len; ++ i)
	{
		int val = query(1, 0, len, i, i);
		if(val >= k)
		{
			update(1, 0, len, i, i, -val + 1);
		}
		else
		{
			update(1, 0, len, i, i, -val + 0);
		}
	}
	
	while(q --)
	{
		int l, r;
		cin >> l >> r;
		int ans = query(1, 0, len, l, r);
		cout << ans << '\n';
	}
	
	return 0;
}




