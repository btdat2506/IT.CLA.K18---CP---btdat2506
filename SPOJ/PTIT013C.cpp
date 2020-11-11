#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll xa, ya, xb, yb;

ll sqr(ll a)
{
	return a*a;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	ll n;
	cin >> n;
	while (n--)
	{
		cin >> xa >> ya >> xb >> yb;
		cout << (ll) sqrt(sqr(xb - xa) + sqr(- abs(yb) - abs(ya))) << "\n";
	}
}