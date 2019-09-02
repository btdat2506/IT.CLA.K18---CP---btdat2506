#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, l1 = -1, l2 = -1, ans = 0, arr1[100010], arr2[100010], pros[100010];

ll bSearch_non_negative(ll x)
{
	ll l = l2, r = n;
	while (r > l)
	{
		ll mid = (l + r) / 2;
		if (abs(arr2[mid]) >= x) r = mid; else l = mid;
	}
	return r;
}

ll bSearch_negative(ll x)
{
	ll l = 1, r = l2;
	while (r > l)
	{
		ll mid = (l + r) / 2;
		if (abs(arr2[mid]) >= x) l = mid; else r = mid;
	}
	return r;
}

void process()
{
	sort(arr1+1, arr1+n+1);
	sort(arr2+1, arr2+n+1);
	For(i, 1, n)
	{
		if (l1 == -1 && arr1[i] >= 0) l1 = i;
		if (l2 == -1 && arr2[i] >= 0) l2 = i;
	}
	if (l1 == -1) l1 = n;
	if (l2 == -1) l2 = n;
	For(i, 1, n)
	if (arr1[i] < 0)
		pros[i] = bSearch_non_negative(arr1[i]);
	else
		pros[i] = bSearch_negative(arr1[i]);
	ans = abs(arr1[1] + arr2[pros[1]]);
	For(i, 2, n)
	ans = min(ans, abs(arr1[i] + arr2[pros[i]]));
	cout << ans << endl;
}

void input()
{
	cin >> n;
	For(i, 1, n)
	cin >> arr1[i];
	For(i, 1, n)
	cin >> arr2[i];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}