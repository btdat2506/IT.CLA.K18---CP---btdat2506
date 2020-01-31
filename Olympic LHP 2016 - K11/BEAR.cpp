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

ll n, m, ans, t[10010], parent[10010];
dt db[100010];

ll find_v(ll u)
{
	while (parent[u] != u)
		u = parent[u];
	return u;
}

void process()
{
	sort(db+1, db+1+n);
	For(i, 1, n) parent[i] = i;
	For(i, 1, m)
	{
		ll u = find_v(db[i].u), v = find_v(db[i].v);
		if (u != v) 
		{
			ans += db[i].c;
			parent[u] = v; //union vertices
		}
	}
	cout << ans << "\n";
}

void input()
{
	cin >> n >> m;
	For(i, 1, n) cin >> t[i];
	For(i, 1, m)
	{
		ll a, b, c;
		cin >> db[i].u >> db[i].v >> db[i].c;
		db[i].c += t[db[i].u] + t[db[i].v] + db[i].c;
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