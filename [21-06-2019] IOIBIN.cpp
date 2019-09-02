#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll par[11000];

ll root(ll x)
{
	if (par[x] < 0) return x;
	return root(par[x]);
}

int main() {
	memset(par, -1, sizeof(par));
	ll p;
	cin >> p;
	For(i, 1, p)
	{
		ll a, b, z;
		cin >> a >> b >> z;
		if (z == 1)
		{
			ll x = root(a),
			   y = root(b);
			if (x == y) continue;
			if (par[x] > par[y]) swap(x, y);
			par[x] += par[y];
			par[y] = x;
		}
		else
		cout << ((root(a) == root(b)) ? 1 : 0) << endl;
	}
	return 0;
}