#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

struct Query
{
	ll l = 0, r = 0, k = 0;
};

bool cmp (const Query &L, const Query &R)
{
	return L.k < R.k;
}

bool cmp_pos(const ll &L, const ll &R)
{
	return a[L] < a[R];
}

Query q[200010];
ll n, qq, a[30010];

void update(ll id, ll l, ll r, ll i, ll v)
{
	if (i < l || r < i) return;
	if (l == r)
	{
		st[id] = v;
		return;
	}
	ll mid = (l + r) / 2;
	update(id*2, l, mid, i, v);
	update(id*2+1, mid+1, r, i, v);	
}

ll get(ll id, ll l, ll r, ll u, ll v)
{
	if (v < l || r < u) return INT64_MIN;
	if (u <= l && r <= v) return st[id];
	ll mid = (l + r) / 2;
	return max(
		get(id*2, l, mid, u, v),
		get(id*2+1, mid+1, r, u, v)
	);
}

void process()
{
	sort(q+1, q+1+qq, cmp);
	sort(pos+1, pos+1+n, cmp_pos);
}

void input()
{
	cin >> n;
	For(i, 1, n) cin >> a[i];
	cin >> qq;
	For(i, 1, q) cin >> q[i].l >> q[i].r >> q[i].k;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}