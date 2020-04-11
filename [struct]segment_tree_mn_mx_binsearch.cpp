const int inf = 2e18;
struct node
{
	int mx, mn, mnid, mxid;
};
struct segtree
{
	vector<node> t;
	void init(int n)
	{
		t.resize(4 * n + 10);
	}
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

};