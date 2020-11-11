#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

pair<ll, ll> node[30010];

ll n;

void process()
{
	For(i, 1, n)
}

void input()
{
	cin >> n;
	ll x1, y1, x2, y2;
	For(i, 1, n)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		node[x1].first = min(node[x1].first, y1);
		node[x2].second = max(node[x2].second, y2);
	}
}

void reset()
{
	For(i, 1, 30005)
	node[i].first = 1e12,
	node[i].second = -1e12;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	input();
	process();
}