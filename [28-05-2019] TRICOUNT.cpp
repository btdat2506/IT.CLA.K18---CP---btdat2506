#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

ll n, ans = 0, a[10000];
vector <ll> cnt[3];

void process()
{
	cnt[1].resize(2000);
	cnt[2].resize(2000);
	cnt[1][0] = cnt[2][0] = 0;

	For(i, 1, n)
	cnt[1][i] = cnt[2][i] = 0;

	For(i, 1, n)
	cnt[1][a[i]]++;

	sort(a+1, a+n+1);

	For(i, a[1], a[n])
	cnt[2][i] = cnt[1][i] + cnt[2][i-1];

	For(i, 1, n-1)
	For(j, i+1, n)
	{
		ll x = min(a[n], (a[i] + a[j]) - 1), y = max(a[1], abs(a[i] - a[j]) + 1);
		ll c = cnt[2][x] - cnt[2][y] + 1;
		//cout << cnt[2][x] << ' ' << cnt[2][y] << endl;
		if (a[i] >= y && a[i] <= x) c--;
		if (a[j] >= y && a[j] <= x) c--;
		//3 cout << a[i] << ' ' << a[j] << ' ' << x << ' ' << y << ' ' << c << endl;
		if (c > 0) ans += c;
	}
	cout << ans/3 << endl;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n;
	For(i, 1, n) cin >> a[i];
	process();
}