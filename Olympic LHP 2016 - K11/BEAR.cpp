#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
#define For(i, a, b) for(ll i = a; i <= b; i++)

struct dt
{
	ll u = 0, v = 0, c = 0;
	bool operator < (const dt &t)
	{
		return c < t.c;
	}
};

ll n, m, ans, t[10010], parent[10010], ranking[10010];
dt db[100010];
map <ii, bool> passed;

ll find_v(ll u)
{
	if (u == parent[u]) return u;
	return parent[u] = find_v(parent[u]);
}

void process()
{
	sort(db+1, db+1+m);
	For(i, 1, n) parent[i] = i;
	For(i, 1, m)
	{
		ll u = find_v(db[i].u), v = find_v(db[i].v);
		if (u != v) 
		{
			ans += db[i].c;
			if (ranking[u] > ranking[v])
				parent[v] = u;
			else
			{
				parent[u] = v;
				if (ranking[u] == ranking[v]) ranking[v]++;
			}
		}
	}
	cout << ans+t[1] << "\n";
}

void input()
{
	cin >> n >> m;
	For(i, 1, n) cin >> t[i];
	For(i, 1, m)
	{
		cin >> db[i].u >> db[i].v >> db[i].c;
		db[i].c = 2*db[i].c + t[db[i].u] + t[db[i].v];
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("BEAR.INP", "r", stdin);
	freopen("BEAR.OUT", "w", stdout);
	input();
	process();
}