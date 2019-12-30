#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;

#define minn first
#define maxx second
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, t, ans, a[100010];
ii st[400010];

void build(ll id, ll l, ll r, ll idx, ll val) 
{
    if (l == r && l == idx) 
	{
		st[id].minn = st[id].maxx = val;
        return ;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid, idx, val);
    build(id * 2 + 1, mid+1, r, idx, val);

    st[id].minn = min(st[id * 2].minn, st[id * 2 + 1].minn);
    st[id].maxx = max(st[id * 2].maxx, st[id * 2 + 1].maxx);
}

ii get(ll id, ll l, ll r, ll u, ll v) 
{
    if (v < l || r < u)
        return ii(-1e9, -1e9);
    if (u <= l && r <= v) 
        return st[id];
    ll mid = (l + r) / 2;

	ii tmp1 = get(id*2, l, mid, u, v),
	   tmp2 =  get(id*2 + 1, mid+1, r, u, v);
	if (tmp1 == ii(-1e9, -1e9)) 
		return tmp2;
	if (tmp2 == ii(-1e9, -1e9))
		return tmp1;
	return ii(min(tmp1.minn, tmp2.minn), max(tmp1.maxx, tmp2.maxx));
}

void process()
{
	For(i, 1, n) build(1, 1, n, i, a[i]);
	For(i, 1, n)
	For(j, i+1, n)
	{
		ii tmp = get(1, 1, n, i, j);
		if (abs(tmp.maxx - tmp.minn) <= t)
		ans = max(ans, j - i + 1);
	}
	cout << ans << "\n";
}

void input()
{
	cin >> n >> t;
	For(i, 1, n)
	cin >> a[i];
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("AMASEQ.INP", "r", stdin);
	freopen("AMASEQ.OUT", "w", stdout);
	input();
	process();
}