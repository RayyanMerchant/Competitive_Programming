vector<int> dsu;
vector<int> num;

void init(int n)
{
	dsu.resize(n + 10);
	num.resize(n + 10);
	for(int i = 0; i <= n; ++ i)
	{
		dsu[i] = i;
		num[i] = 1;
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
		if(num[u] < num[v]) swap(u, v);
		num[u] += num[v];
		dsu[v] = u;
	}
}