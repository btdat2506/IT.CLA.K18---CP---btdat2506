#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, t[60010], r[60010], res[60010], res2[60010];

void process()
{
	res[1] = t[1];
	res[2] = min(res[1] + t[2], r[1]);
	For(i, 3, n)
	{
		res[i] = min(res[i-1] + t[i], res[i-2] + r[i-1]);
	}
	cout << res[n] << "\n";
}

void input()
{
	cin >> n;
	For(i, 1, n) cin >> t[i];
	For(i, 1, n-1) cin >> r[i];
}

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	input();
	process();
}