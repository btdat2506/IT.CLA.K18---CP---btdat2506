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
	For(k, 3, n)
	{
		ll cnt = 1;
		double a[2010];
		For(i, 1, k-1)
		{
			ll dx = (db[i].x - db[k].x),
			   dy = (db[i].y - db[k].y);
			if (dy == 0) a[i] = 1e6;
			else
				a[i] = dx / dy;
		}
		sort(a+1, a+k);
		For(i, 2, k-1)
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
	freopen("dl.inp", "r", stdin);
	freopen("kq.out", "w", stdout);
	input();
	process();
}