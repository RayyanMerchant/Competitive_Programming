vector<int> fact, invfact, two;

int modpow(int x, int y, int p = mod) 
{ 
	int res = 1;       
	x %= p;   
	while (y > 0) 
	{ 
		if (y & 1) 
			res = (res * x) % p; 
		y >>= 1;
		x = (x * x) % p;   
	} 
	return res; 
} 
int add(int x, int y) 
{
	x += y;
	if (x >= mod) return x - mod;
	return x;
}
int sub(int x, int y) 
{
	x -= y;
	if (x < 0) return x + mod;
	return x;
}
int inv(int a, int m = mod)
{
	return modpow(a, m - 2, m);
}
int mul(int a, int b) 
{
	return (long long) a * b % mod;
}

void calc_fact(int n)
{
	fact.resize(n);
	invfact.resize(n);
	two.resize(n);
	fact[0] = invfact[0] = two[0] = 1;
	for(int i = 1; i < n; ++ i)
	{
		fact[i] = mul(fact[i - 1], i);
		invfact[i] = inv(fact[i]);
		two[i] = mul(two[i - 1], 2);
	}
}

int ncr(int n, int r)
{
	assert(n >= r && n >= 0 && r >= 0);
	int ans = mul(fact[n], mul(invfact[n - r], invfact[r]));
	return ans;
}

vector<vector<int>> choose(M + 1, vector<int>(M + 1));
for(int i = 0; i <= M; ++ i) 
{
	choose[i][0] = choose[i][i] = 1;
	for(int j = 1; j < i; ++ j) 
	{
		choose[i][j] = add(choose[i - 1][j - 1], choose[i - 1][j]);
	}
}

