#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

ll n, a[300010], l[300010], r[300010], d[300010];

void process()
{
	d[0] = 0;
	ll top = 0;
	For(i, 1, n)
	{
		while (a[i] <= a[d[top]] && top > 0) top--;
		l[i] = d[top] + 1;
		d[++top] = i;
	}
	memset(d, 0, sizeof(d));
	d[0] = n+1;
	top = 0;
	Fod(i, n, 1)
	{
		while (a[i] <= a[d[top]] && top < n) top--;
		r[i] = d[top] - 1;
		d[++top] = i;
	}
	ll ans = 0, left = 0, right = 0;
	For(i, 1, n)
	if ((r[i] - l[i] + 1) * a[i] > ans)
		ans = (r[i] - l[i] + 1) * a[i],
		left = l[i], right = r[i];
	cout << ans << ' ' << left << ' ' << right << endl;
}

void input()
{
	cin >> n;
	For(i, 1, n)
	cin >> a[i];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll t = 0;
	cin >> t;
	For(i, 1, t)
	{
		memset(a, 0, sizeof(a));
		memset(l, 0, sizeof(l));
		memset(r, 0, sizeof(r));
		memset(d, 0, sizeof(d));
		input();
		process();
	}
}