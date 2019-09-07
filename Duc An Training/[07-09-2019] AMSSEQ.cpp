#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i++)

ll n, k, ans, db[10010], f[10010];

void process()
{
	For(i, 1, n) f[i] = INT64_MIN;
	f[1] = max((ll) 0, db[1]);
	For(i, 2, n)
	{
		ll j = 1;
		while (i-j >= 1 && j <= k)
		{
			f[i] = max(f[i], f[i-j] + db[i]),
			j++;
		}
		ans = max(ans, f[i]);
	}
	cout << ans << endl;
}

void input()
{
	cin >> n >> k;
	For(i, 1, n)
	cin >> db[i];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}