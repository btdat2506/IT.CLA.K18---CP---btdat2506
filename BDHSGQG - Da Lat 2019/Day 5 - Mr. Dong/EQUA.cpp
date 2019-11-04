#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)


ll n, a, b, c, ans, delta;
double x, x1, x2;

map <double, bool> cnt;

void solve()
{
	x1 = (double) (-b + sqrt(delta)) / (double) (2*a);
	if (cnt[x1] == 0)
		cnt[x1] = 1,
		ans++;
	if (delta > 0)
	{
		x2 = (double) (-b - sqrt(delta)) / (double) (2*a);
		if (cnt[x2] == 0)
			cnt[x2] = 1,
			ans++;
	}
}

int main()
{
	freopen("EQUA.INP", "r", stdin);
	freopen("EQUA.OUT", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	For(i, 1, n)
	{
		cin >> a >> b >> c;
		if (a == 0)
		{
			if (b == 0)
			{
				if (c == 0)
				{
					cout << -1;
					return 0;
				}
				continue;
			}
			if (b != 0)
			{
				x = (double) -c / (double) b;
				if (cnt[x] == 0)
					cnt[x] = 1,
					ans++;
			}
		}
		else
		if ((delta = b*b - 4*a*c) >= 0)
		solve();
	}
	cout << ans << endl;
	system("pause");
}