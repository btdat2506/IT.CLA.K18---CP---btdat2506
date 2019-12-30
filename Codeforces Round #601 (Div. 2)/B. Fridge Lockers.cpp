#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, m, res;

void process()
{
	if (m < n || n < 3)
	{
		cout << -1 << "\n";
		return;
	}
	cout << res << "\n";
	For(i, 1, n)
	cout << i << ' ' << i % n + 1 << '\n';
}

void input()
{
	cin >> n >> m;
	For(i, 1, n)
	{
		ll x;
		cin >> x;
		res += x << 1;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll t;
	cin >> t;
	while (t--)
	{
		res = 0;
		input();
		process();
	}
}