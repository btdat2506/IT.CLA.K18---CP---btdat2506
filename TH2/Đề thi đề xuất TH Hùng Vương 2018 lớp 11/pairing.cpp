#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

int main()
{
	freopen("pairing.inp", "r", stdin);
	freopen("pairing.out", "w", stdout);
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << a%2 + b%2 + abs(c - d) << "\n";
}