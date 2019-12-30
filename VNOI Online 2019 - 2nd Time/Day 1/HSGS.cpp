#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, x, y, gcd_arr, a[1000000];

ll try_go(ll result, ll idx)
{
	if (gcd_arr == 1) return -1;
	if (idx == n)
	{
		return __gcd(a[idx], gcd_arr);
	}
	if (idx == 1) 
		gcd_arr = a[1];
	else
		gcd_arr = __gcd(a[idx], gcd_arr);
	
	
}

void process()
{
	if (gcd_arr != 1) 
	{
		cout << gcd_arr << "\n";
		return;
	}
	else
	cout << try_go(0, 1) << '\n';
}

void input()
{
	cin >> n >> x >> y;
	For(i, 1, n)
	{
		cin >> a[i];
		gcd_arr = (i == 1) ? a[i] : __gcd(a[i], gcd_arr);
	}
}

int main()
{
	freopen("HSGS.INP", "r", stdin);
	freopen("HSGS.OUT", "w", stdout);
	ll t;
	cin >> t;
	while (t--)
	{
		input();
		process();
	}
}