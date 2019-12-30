#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair <ll, ll> ii;
#define For(i, a, b) for(ll i = a; i <= b; i++)

const ll N = 1e4 + 5;
ll n, m, s, len[N], cnt[N];
vector <ll> a[N];
queue <ll> qu;
map <ii, bool> dd;

void process()
{
	len[s] = 0;
	cnt[s] = 1;
	qu.push(s);
	while (!qu.empty())
	{
		ll u = qu.front();
		qu.pop();
		for (ll v: a[u])
		if (!cnt[v])
		{
			len[v] = len[u] + 1;
			cnt[v] = cnt[u];
			qu.push(v);
		}
		else
			if (len[v] == len[u] + 1 && cnt[v] == 1) cnt[v] = 2;
	}
	ll res = 0;
	For(i, 1, n)
	res += (cnt[i] == 2);
	cout << res << "\n";
}

void input()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> s;
	For(i, 1, m)
	{
		ll u, v;
		cin >> u >> v;
		if (dd[{u, v}]) continue;
		dd[{u, v}] = 1;
		a[u].push_back(v);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}