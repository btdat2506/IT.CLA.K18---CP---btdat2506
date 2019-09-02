#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll t = 0;
	cin >> t;
	while (t--)
	{
		ll n = 0, k = 0, ans = 0;
		cin >> n >> k;
		while (n)
		if (n % k == 0) 
			n /= k,
			ans++;
		else
			ans += n % k,
			n -= n % k;
		cout << ans << endl;
	}
}