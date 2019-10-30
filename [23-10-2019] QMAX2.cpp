#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

struct SegmentTree
{
	ll val = 0, lazy = 0;
};

SegmentTree st[10230997];
ll n, m, p, a[50010];
 
void down(ll id)
{
	ll t = st[id].lazy;
	st[id*2].val += t;
	st[id*2].lazy += t;

	st[id*2 + 1].val += t;
	st[id*2 + 1].lazy += t;

	st[id].lazy = 0;
}

void update(ll id, ll l, ll r, ll u, ll v, ll val)
{
	if (v < l || u > r) return;
	if (l >= u && r <= v)
	{
		st[id].val += val;
		st[id].lazy += val;
		return;
	}
	ll mid = (l + r) / 2;
	down(id);
	update(id*2, l, mid, u, v, val);
	update(id*2+1, mid+1, r, u, v, val);
	st[id].val = max(st[id*2].val, st[id*2+1].val);
}

ll get(ll id, ll l, ll r, ll u, ll v)
{
	if (v < l || u > r) return 0;
	if (l >= u && r <= v) return st[id].val;
	ll mid = (l + r) / 2;
	down(id);
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
		bool Type;
		cin >> Type;
		if (!Type)
		{
			ll l, r, val;
			cin >> l >> r >> val;
			update(1, 1, n, l, r, val);
		}
		else
		{
			ll l, r;
			cin >> l >> r;
			cout << get(1, 1, n, min(l, r), max(l, r)) << "\n";
		}
	}
}
