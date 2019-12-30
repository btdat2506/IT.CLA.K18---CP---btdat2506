#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
#define val first
#define idx second	
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define f0(i, b) for(ll i = 0; i < b; i++)

ll n, m, c[100010], f[100010], rmq[100010][20];

void range_minimum_query()
{
	For(i, 1, n)
	rmq[i][0] = i;

	for(ll j = 1; 1 << j <= n; j++)
	for(ll i = 1; i + (1 << j) < n; i++)
	if (c[rmq[i][j - 1]] < c[rmq[i + (1 << (j - 1))][j - 1]])
		rmq[i][j] = rmq[i][j - 1];
	else
		rmq[i][j] = rmq[i + (1 << (j - 1))][j - 1];
}

ll get_min(ll i)
{
	ll range = log2(m),
	   j = i + m - 1;
	if (c[rmq[i][range]] <= c[rmq[j - (1 << range) + 1][range]])
		return rmq[i][range];
	else
		return rmq[j - (1 << range) + 1][range];
}

void subtask1()
{
	For(i, 1, m) f[i] = c[i];
	For(i, m+1, n) f[i] = 1e9;
	For(i, m+1, n)
	{
		For(j, i-m, i)
		f[i] = min(f[i], f[j]);
		f[i] += c[i];
	}
	cout << f[n] << "\n";
}

void subtask2()
{
	range_minimum_query();
	ll ans = 0;
	for(ll i = get_min(1); i <= n && i >= 1; i = get_min(i+1))
	{
		ans += c[i];
		if (i >= n-m) break;
	}
	cout << ans << "\n";
}

void process()
{
	if (n * m > 1e8) 
		subtask2();
	else
		subtask1();
}

void input()
{
	cin >> n >> m;
	For(i, 1, n)
	cin >> c[i];
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("NASA.INP", "r", stdin);
	freopen("NASA.OUT", "w", stdout);
	input();
	process();
}