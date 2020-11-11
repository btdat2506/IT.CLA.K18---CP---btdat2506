#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
typedef pair<ll, string> istr;
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define f0(i, n) for(ll i = 0; i < n; i++)
//ifstream (NAME);
//ofstream (NAME);

string s[301];
ll n, m, le[301][301], up[301][301], used[301][301][2];

void dfs()

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	cin >> n >> m;
	f0(i, n)
	{
		cin >> s[i];
		if (s[i][0] == '.' le[i][0] = i;
		for(int j = 1; j < m; j++)
		if (s[i][j] == '#') le[i][j] = 0;
		else
			le[i][j] = le[i][j-1] + 1;
	}
	//binary search
	int le = 0, ri = min(n, m) + 1, mi;
	while (ri - le > 1)
	{
		mi = le + ri / 2;
		bool d = 0;
		f0(i, n)
		f0(j, m)
		used[i][j][0] = used[i][j][1] = 0;
		f0(i, n - mi + 1)
		if (up[i + mi - 1][0]) >= mi && used[i][0][0] == 0)
			dfs(i, 0, 0);
		f0(i, n - mi + 1)
		if (used[i][m-1][0])
		{
			d = 1;
			break;
		}
		if (d) le = mi; else ri = mi;
	}
}