#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

void process(ll n)
{
	For(x, 1, sqrt(n))
	{
		ll y = n - x*x, sqrt_y = sqrt(y);
		if (sqrt_y * sqrt_y == y)
		{
			cout << "Yes" << endl;
			return;
		}
	}
	cout << "No" << endl;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll n;
	cin >> n;
	while (n--)
	{
		ll x;
		cin >> x;
		process(x);
	}
}