#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll s, n, v[2010], w[2010], f[2010][2010];

void process()
{
	For(i, 1, n)
	For(j, 1, s)
	{
		f[i][j] = f[i-1][j];
		if (w[i] <= j)
			f[i][j] = max(f[i-1][j], f[i-1][j-w[i]] + v[i]);
	}
	cout << f[n][s] << "\n";
}
 
void input()
{
	cin >> s >> n;
	For(i, 1, n)
	cin >> w[i] >> v[i];
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	input();
	process();
}