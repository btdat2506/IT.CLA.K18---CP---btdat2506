#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll max(ll a, ll b, ll c)
{
	return max(a, max(b, c));
}

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	ll n;
	cin >> n;
	For(i, 1, n)
	{
		ll r, g, b;
		cin >> r >> g >> b;
		cout << max(min(r, g + b), min(r + g,  b), min(r + b, g)) << "\n";
	}
}
