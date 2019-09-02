#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

struct dt
{
	ll u = 0, v = 0, c = 0;
};

bool cmp(const dt &L, const dt &R)
{
	return L.c < R.c;
}

dt db[100010];
ll n, ans = INT64_MAX, p, times[10010], par[10010];

ll root(ll x)
{
	if (par[x] == x) return x;
	return par[x] = root(par[x]);
}

void process()
{
	sort(db+1, db+p+1, cmp);
	For(i, 1, n)
	par[i] = i,
	ans = min(ans, times[i]);
	For(i, 1, p)
	{
		ll u = root(db[i].u),
		   v = root(db[i].v);
		if (u != v)
		{
			par[v] = u,
			ans += db[i].c;
		}
	}
	cout << ans << endl;
}

void input()
{
	cin >> n >> p;
	For(i, 1, n) cin >> times[i];
	For(i, 1, p)
	{
		ll u, v, c;
		cin >> u >> v >> c;
		db[i].u = u,
		db[i].v = v,
		db[i].c = c*2+times[u]+times[v];
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();

}
