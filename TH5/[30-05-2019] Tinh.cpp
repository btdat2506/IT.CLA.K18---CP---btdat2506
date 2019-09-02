#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

ll x(ll n)
{
	if (n <= 0) return 1;
	ll s = 0;
	For(i, 1, n) s += i*i*x(n-i);
	return s;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll n = 0;
	cin >> n;
	cout << x(n) << endl;
}

// n^2 * x(0) + (n-1)^2 * x(1)