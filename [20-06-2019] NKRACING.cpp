#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

struct dat
{
	ll u = 0, v = 0, c = 0;
};

bool cmp(const dat &L, const dat &R)
{
	return L.c > R.c;
}

ll n, m, ans = 0, par[10010];
dat db[100010];

ll root(ll x)
{
	if (par[x] == x) return x;
	return par[x] = root(par[x]);
}

void process()
{
	sort(db+1, db+m+1, cmp);
	For(i, 1, n) par[i] = i;
	For(i, 1, m) ans += db[i].c;
	For(i, 1, m)
	{
		ll u = root(db[i].u),
		   v = root(db[i].v);
		if (u != v)
			ans -= db[i].c,
			par[u] = v;
	}
	cout << ans << endl;
}

void input()
{
	memset(par, -1, sizeof(par));
	cin >> n >> m;
	For(i, 1, m)
	cin >> db[i].u >> db[i].v >> db[i].c;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	input();
	process();
}