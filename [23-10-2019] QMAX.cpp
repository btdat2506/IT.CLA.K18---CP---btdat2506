#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, m, p, st[10230997], a[50010];

void update(ll id, ll l, ll r, ll v)
{
	if (v < l || v > r) return;
	if (l == r)
	{
		st[id] = a[v];
		return;
	}
	ll mid = (l + r) / 2;
	update(id*2, l, mid, v);
	update(id*2+1, mid+1, r, v);
	st[id] = max(st[id*2], st[id*2+1]);
}

ll get(ll id, ll l, ll r, ll u, ll v)
{
	if (v < l || u > r) return 0;
	if (l >= u && r <= v) return st[id];
	ll mid = (l + r) / 2;
	return max( get(id*2, l, mid, u, v), 
				get(id*2+1, mid+1, r, u, v));
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n >> m;
	For(i, 1, m)
	{
		ll u, v, k;
		cin >> u >> v >> k;
		a[u] += k;
		a[v+1] -= k;
	}
	For(i, 2, n) 
	{
		a[i] += a[i-1];
		update(1, 1, n, i);
	}
	cin >> p;
	For(j, 1, p)
	{
		ll l, r;
		cin >> l >> r;
		cout << get(1, 1, n, min(l, r), max(l, r)) << "\n";
	}
}
