#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
typedef pair<ll, string> istr;
typedef tuple<ll, ll, ll> iii;
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define f0(i, n) for(ll i = 0; i < n; i++)
//ifstream (NAME);
//ofstream (NAME);

ll n, k, res;
tuple <ll, ll, ll> a[1000010];
vector <ll> t;

void compress_array()
{
	vector <ll> t1;
	sort(t.begin(), t.end());
	t.erase(unique(t.begin(), t.end()), t.end());
	f0(i, n)
	{
		ll s, d, r;
		tie(r, s, d) = a[i];
		s = lower_bound(t.begin(), t.end(), s) - t.begin();
		d = lower_bound(t.begin(), t.end(), d) - t.begin();
		a[i] = tie(r, s, d);
	}
}

ll parent[(ll) (1e6+10)];

ll root(ll u)
{
	if (parent[u] == u) return u;
	return parent[u] = root(parent[u]);
}

void union_dsu(ll u, ll v)
{
	parent[v] = u;
}

void dsu()
{
	//init
	f0(i, t.size()+2)
	parent[i] = i;
	sort(a+1, a+1+n, greater<iii>());
	f0(i, n)
	{
		ll r, s, d;
		tie(r, s, d) = a[i];
		ll availableSlot = root(d);
		if (availableSlot > 0)
		{
			union_dsu(s-1, d);
			res += r;
		}
	}
}

void process()
{
	compress_array();
	/* f0(i, n)
	{
		ll s, d, r;
		tie(s, d, r) = a[i];
		cout << s << ' ' << d << ' ' << r << '\n';
	} */
	dsu();
	cout << res << "\n";
}

void input()
{
	ll s, d, r;
	cin >> n >> k;
	f0(i, n)
	{
		cin >> s >> d >> r;
		d += k;
		a[i] = tie(r, s, d);
		t.push_back(s); t.push_back(d);
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	input();
	process();
}