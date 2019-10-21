#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

struct point
{
	ll x = 0, y = 0;
};

ll n, ans;
point db[2010];

void process()
{
	double a[2010];
	For(k, 3, n)
	{
		ll cnt = 1;
		For(i, 1, k)
		{
			ll dx = (db[i].x - db[k].x),
			   dy = (db[i].y - db[k].y);
			if (dy == 0) a[i] = 1e6;
			else
				a[i] = dx / dy;
		}
		sort(a+1, a+k+1);
		For(i, 2, k)
		{
			if (a[i] != a[i-1])
			{
				ans += (cnt * (cnt-1)) / 2;
				cnt = 0;
			}
			else cnt++;
		}
		ans += (cnt * (cnt - 1)) / 2;
	}
	cout << ans << "\n";
}

void input()
{
	cin >> n;
	For(i, 1, n)
	cin >> db[i].x >> db[i].y;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}