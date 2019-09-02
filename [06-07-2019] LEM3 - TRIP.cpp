#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i < b; i++)

ll n, ans = INT64_MAX, c[20][20], f[20][32770];

bool getbit(ll x, ll i)
{
	return (x >> i) & 1;
}

void process()
{

	For(i, 0, n)
	For(x, 0, (1 << n)) 
	f[i][x] = 1000000000;

	For(i, 0, n)
	f[i][1 << i] = 0;

	For(x, 0, (1 << n))
	For(i, 0, n)
	if (getbit(x, i))
	{
		ll s = x ^ (1 << i);
		For(j, 0, n)
		if (getbit(s, j))
		f[i][x] = min(f[i][x], f[j][s] + c[j][i]);
	}
	For(i, 0, n)
	ans = min(ans, f[i][(1<<n)-1]);
	cout << ans << endl;
}

void input()
{
	cin >> n;
	For(i, 0, n)
	For(j, 0, n)
	cin >> c[i][j];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
} 