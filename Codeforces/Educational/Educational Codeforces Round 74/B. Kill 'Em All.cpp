#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll q;
	cin >> q;
	while (q--)
	{
		ll n, r, ans = -1;
		cin >> n >> r;
		For(i, 1, n)
		{
			ll x;
			cin >> x;
			ll tmp = x / r;
			if (x % r != 0) tmp++;
			cout << tmp << "\n";
			ans = max(ans, tmp);
		}
		cout << "\n";
		cout << ans << "\n";
	}	
}