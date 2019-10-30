#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, m, st[10230997];

void update(ll id, ll l, ll r, ll i, ll v)
{
	if (i < l || i > r) return;
	if (l == r)
	{
		st[id] = v;
		return;
	}
	ll mid = (l + r) / 2;
	update(id*2, l, mid, i, v);
	update(id*2+1, mid+1, r, i, v);
	st[id] = st[id*2] + st[id*2+1];
}

ll get(ll id, ll l, ll r, ll u, ll v)
{
	if (v < l || u > r) return 0;
	if (l >= u && r <= v) return st[id];
	ll mid = (l + r) / 2;
	return get(id*2, l, mid, u, v) +
		   get(id*2+1, mid+1, r, u, v);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n >> m;
	For(i, 1, n)
	{
		ll x;
		cin >> x;
		update(1, 1, n, i, x);
	}
	For(j, 1, m)
	{
		ll a, l, r;
		cin >> a >> l >> r;
		if (a == 1) update(1, 1, n, l, r);
		else
		cout << get(1, 1, n, min(l, r), max(l, r)) << "\n";
	}
}
