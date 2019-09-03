#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, l1 = -1, l2 = -1, ans = 0, arr1[100010], arr2[100010], pos[100010];

void process()
{
	sort(arr2+1, arr2+n+1);
	For(i, 1, n)
		pos[i] = min(abs(arr1[i] + arr2[lower_bound(arr2+1, arr2+n+1, -arr1[i]) - arr2]),
					abs(arr1[i] + arr2[upper_bound(arr2+1, arr2+n+1, -arr1[i]) - arr2]));

	ans = pos[1];
	For(i, 2, n)
	ans = min(ans, pos[i]);
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