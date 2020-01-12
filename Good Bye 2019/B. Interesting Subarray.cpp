#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, arr[1000010];

void process()
{
	For(i, 1, n-1)
	if (abs(arr[i] - arr[i+1]) >= 2)
	{
		cout << "YES" << "\n";
		cout << i << ' ' << i+1 << "\n";
		return;
	}
	cout << "NO" << "\n";
}

void input()
{
	cin >> n;
	For(i, 1, n)
	cin >> arr[i];
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	ll t;
	cin >> t;
	while (t--)
	{
		input();
		process();
	}
}