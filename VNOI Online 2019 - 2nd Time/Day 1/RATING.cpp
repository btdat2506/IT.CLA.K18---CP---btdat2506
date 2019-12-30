#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

bool sub2 = 1, sub3 = 1;
ll n, q, x, l, r, prefix_sum[100010], a[100010];

void process1()
{
	For(k, l, r)
	{
		x = abs(x - a[k]);
	}
	cout << x << "\n \n";
}

void process3()
{
	ll cnt = min(x / a[1], (r - l) + 1);
	x -= cnt * a[1];
	cnt = ((r - l) + 1) - cnt;
	cout << ((cnt % 2) ? abs(x - a[1]) : x) << "\n";
}

void process()
{
	For(i, 1, q)
	{
		cin >> x >> l >> r;
		if (sub3) process3();
		else
		if (x >= prefix_sum[r] - prefix_sum[l-1]) 
			cout << abs(x - prefix_sum[r] + prefix_sum[l-1]) << "\n"; // sub2
		else
		process1();
	}
}

void input()
{
	memset(prefix_sum, 0, sizeof(prefix_sum));
	sub2 = sub3 = 1;
	cin >> n >> q;
	For(i, 1, n)
	{
		cin >> a[i];
		if (a[i] > 1000) sub2 = false;
		if (a[i] != a[i-1] && i != 1) sub3 = false;
		prefix_sum[i] = prefix_sum[i-1] + a[i];
	}
}

int main()
{
	freopen("RATING.INP", "r", stdin);
	freopen("RATING.OUT", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	ll t;
	cin >> t;
	while (t--)
	{
		input();
		process();
	}
}