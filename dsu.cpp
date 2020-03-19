
vector<int> dsu(maxn);
vector<int> sz(maxn);

void init(int n)
{
	for(int i = 0; i <= n; ++ i)
	{
		dsu[i] = i;
		sz[i] = 1;
	}
}

int root(int p)
{
	return (p == dsu[p]) ? p : dsu[p] = root(dsu[p]);
}

void merge(int u, int v)
{
	u = root(u);
	v = root(v);
	if(u != v)
	{
		if(sz[u] < sz[v]) swap(u, v);
		sz[u] += sz[v];
		dsu[v] = u;
	}
}