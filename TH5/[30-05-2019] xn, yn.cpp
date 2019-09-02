#include <bits/stdc++.h>

using namespace std;

#define ll int64_t

ll x(ll n);
ll y(ll n);

ll x(ll n)
{
	if (n == 0) return 1;
	return x(n-1) + y(n-1);
}

ll y(ll n)
{
	if (n == 0) return 0;
	return 3*x(n-1) + 2*y(n-1);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll n = 0;
	cin >> n;
	cout << "x: " << x(n) << endl << "y: " << y(n) << endl;
}

/*
	x(0) = 1, y(0) = 0
	x(n) = x(n-1) + y(n-1)
	y(n) = 3x(n-1) + 2y(n-1)
*/