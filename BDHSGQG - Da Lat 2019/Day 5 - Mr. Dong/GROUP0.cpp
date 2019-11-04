#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, k, a[60];

ll ck(ll cnt)
{
	ll sum = 0;
	For(i, 1, n)
	if (a[i] >= cnt)
		sum += cnt;
	else
		sum += a[i];
	if (sum >= k*cnt) return cnt; else return 0;
}

ll bSearch(ll l, ll r)
{
	ll mid = (l + r) / 2;
	while (l != mid && r != mid)
	{
		if (ck(mid) <= res)
			r = i;
		else
			l = i,
			res = mid;
		mid = (l + r) / 2; 
	}
}

int main()
{
	freopen("GROUP0.INP", "r", stdin);
	freopen("GROUP0.OUT", "w", stdout);
	cin >> n >> k;
	For(i, 1, n) cin >> a[i];
}