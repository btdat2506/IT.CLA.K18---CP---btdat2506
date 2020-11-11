#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
typedef pair<ll, bool> ib;
#define f0(i, n) for(ll i = 0; i < n; i++)

ll n;
vector <ib> a;
vector <ii> res;

void process()
{
	sort(a.begin(), a.end());
	ll l = a[0].first, c = 1;
	for(ll i = 1; i < 2*n; i++)
	{
		if (a[i].second) c--; else c++;
		if (c == 0)
		{
			res.push_back({l, a[i].first});
			l = a[i+1].first;
		}
	}
	a.resize(0);
	for(ll i = 0; i < res.size(); i++)
	{
		if ()
	}
}

void input()
{
	ll x, y;
	cin >> n;
	a.resize(2*n);
	f0(i, n)
	{
		cin >> x >> y;
		a[2*i] = {x, 0};
		a[2*i+1] = {y, 1};
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	input();
	process();
}