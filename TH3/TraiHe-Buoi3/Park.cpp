#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
//n = 10^5
ll n, m, par[100010];
vector <ll> ans[100010];

ll root(ll x)
{
	if (par[x] == x) return x;
	return root(par[x]);
}

void setroot(ll a, ll x)
{
	if (par[a] != a) setroot(par[a], x);
	par[a] = x;
}

void process()
{
	For(i, 1, n) cout << par[i] << ' '; cout << endl;
	For(i, 1, n)
	{
		ll x = root(i);
		ans[x].push_back(i);
	}
	For(i, 1, n)
	{
		for(ll j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << ' ';
		cout << endl;
	}
}

void input()
{
	cin >> n >> m;
	For(i, 1, n) par[i] = i;
	For(i, 1, m)
	{
		ll a, b;
		cin >> a >> b;
		ll x = root(a),
		   y = root(b);
		if (x < y) 
		setroot(a, x); else
		setroot(b, x);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}