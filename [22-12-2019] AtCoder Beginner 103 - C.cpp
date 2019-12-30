#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

int main()
{
	ll n, x, ans = 0;
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	cin >> n;
	while (n--)
	{
		cin >> x;
		ans += x - 1;
	}
	cout << ans << "\n";
}