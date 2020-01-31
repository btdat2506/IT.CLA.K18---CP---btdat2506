#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

void process()
{
	ll n = 0, ans = 0;
	set <ll> even;
	cin >> n;
	For(i, 1, n)
	{
		ll elem;
		cin >> elem;
		if (elem % 2 == 0) even.insert(elem);
	}
	while (!even.empty())
	{
		ll m = *even.rbegin();
		even.erase(m);
		if (m % 2 == 0)
		{
			ans++;
			if ((m / 2) % 2 == 0) even.insert(m / 2);
		}
	}
	cout << ans << "\n";
}



int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	ll t;
	cin >> t;
	while (t--)
	{
		process();
	}
}