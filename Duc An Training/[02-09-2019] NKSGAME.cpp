#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, ans = INT64_MAX, arr1[100010], arr2[100010];

ll bSearch(ll x)
{
	ll l = 1, r = n;
	while (r >= l)
	{
		ll mid = (l + r) / 2;
		if (arr2[mid] == -x) return mid;
		if (arr2[mid] > -x) r = mid-1; else l = mid+1;
	}
	if (l>n) return r;
	if (r<1) return l;
	if (abs(x + arr2[l]) < abs(x + arr2[r])) return l; else return r;
}

void process()
{
	sort(arr2+1, arr2+n+1);
	For(i, 1, n)
	{	
		ll x, y = lower_bound(arr2+1, arr2+n+1, -arr1[i]) - arr2;
		if (y > 1) x = y - 1; else x = y;
		ans = min(ans, min(abs(arr1[i] + arr2[x]), abs(arr1[i] + arr2[y])));
	}
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