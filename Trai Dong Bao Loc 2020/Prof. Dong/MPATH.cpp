#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
typedef pair<ll, string> istr;
#define fi first
#define se second
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define f0(i, n) for(ll i = 0; i < n; i++)
//ifstream (NAME);
//ofstream (NAME);

ll ans;
vector <ii> edge;
map<ll, ll> f;

bool cmp(const ii &a, const ii &b)
{
	return (a.se < b.se || (a.se == b.se && a.fi < b.fi));
}

void process()
{
	sort(edge.begin(), edge.end(), cmp);
	for(ii t: edge)
	{
		f[t.second] = max(f[t.second], f[t.first] + 1);
		ans = max(ans, f[t.second]);
	}
	cout << ans << "\n";
}

void input()
{
	ll m, u, v;
	cin >> m;
	For(i, 1, m)
	{
		cin >> u >> v;
		edge.push_back({u, v});
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	input();
	process();
}