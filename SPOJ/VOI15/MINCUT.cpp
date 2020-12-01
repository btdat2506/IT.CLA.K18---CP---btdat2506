#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll m, n, k, f[1010][1010];
ll a, b, u, v, res;

ll getValUpLeft(ll pos, bool mode)
{
	if (mode == 0)
	{
		return f[pos][v] - f[a-1][v] - f[pos][b-1] + f[a-1][b-1];
	}
	if (mode == 1)
	{
		return f[u][pos] - f[a - 1][pos] - f[u][b - 1] + f[a-1][b-1];
	}
}

ll getValDownRight(ll pos, bool mode)
{
	if (mode == 0)
	{
		return f[u][v] - f[pos][v] - f[u][b-1] + f[pos][b-1];
	}
	if (mode == 1)
	{
		return f[u][v] - f[a - 1][v] - f[u][pos] + f[a - 1][pos];
	}
}

void bSearch(ll l, ll r, bool mode)
{
	//mode 0 = from top to down
	//mode 1 = left to right
	ll t1, t2, mid = (l + r) >> 1;
	while (l != mid && r != mid)
	{
		t1 = getValUpLeft(mid, mode),
		t2 = getValDownRight(mid, mode);
		if (t1 < t2)
			l = mid;
		else
			r = mid;
		mid = (l + r) >> 1;
	}
	For(i, l, r)
	res = min(res, abs(getValUpLeft(i, mode) - getValDownRight(i, mode)));
	//return res;
}

void process()
{
	ll t1, t2;
	/* For(i, 1, m)
	{
		For(j, 1, n)
		cout << f[i][j] << ' '; cout << "\n";
	} */
	while (k--)
	{
		res = 1e14;
		cin >> a >> b >> u >> v;
		/* For(i, a, u - 1)
		{
			t1 = f[i][v] - f[a-1][v] - f[i][b-1] + f[a-1][b-1],
			t2 = f[u][v] - f[i][v] - f[u][b-1] + f[i][b-1];
			
			//cout << i << ' ' << t1 << ' ' << t2 << '\n';
			res = min(res, abs(t1 - t2));
		}

		For(i, b, v - 1)
		{
			t1 = f[u][i] - f[a - 1][i] - f[u][b - 1] + f[a-1][b-1],
			t2 = f[u][v] - f[a - 1][v] - f[u][i] + f[a - 1][i];
			
			//cout << i << ' ' << t1 << ' ' << t2 << '\n';
			res = min(res, abs(t1 - t2));
		} */
		if (u-1 >= a) bSearch(a, u-1, 0);
		if (v-1 >= b) bSearch(b, v-1, 1);
		cout << res << "\n";
	}
}

void input()
{
	cin >> m >> n >> k;
	For(i, 1, m)
	For(j, 1, n)
	{
		cin >> f[i][j];
		f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + f[i][j];
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	input();
	process();
}