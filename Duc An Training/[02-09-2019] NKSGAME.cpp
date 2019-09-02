#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, l1 = -1, l2 = -1, arr1[100010], arr2[100010];

ll bSearch(ll x)
{
	ll l = 1, r = n;
	while (r >= l)
	{
		ll mid = (l + r) / 2;
		if (abs(x + db[mid]))
	}
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
	For(i, 1, n)
	{

	}
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