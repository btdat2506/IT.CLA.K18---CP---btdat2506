#include <bits/stdc++.h>

using namespace std;

typedef uint64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

int main()
{
//	freopen("test.in", "r", stdin);
//	freopen("test.ok", "w", stdout);
	ll n, res = 1e17;
	cin >> n;
	For(i, 1, sqrt(n) + 1)
	if (n % i == 0)
	res = min(res, i + n/i - 2);
	cout << res << "\n";
}